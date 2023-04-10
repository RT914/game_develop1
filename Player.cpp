#include <Eigen/Dense>
#include <stdio.h>
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Scene.h"
#include "SpriteComponent.h"
#include "Component.h"
#include "ColliderComponent.h"
#include "Missile.h"

Player::Player(Game* game)
    :Actor(game)
    , mRightMove(0.0f)
    , mDownMove(0.0f)
    , mIsCanShot(false)
    , mDeltaShotTime(0.0f)
    , mTexWidth(0.0f)
    , mTexHeight(0.0f)
{
    
    // �X�v���C�g�ݒ�
    auto* sprite = new SpriteComponent(this);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "player.png"));
    mTexWidth = sprite->GetTexWidth();
    mTexHeight = sprite->GetTexHeight();
    // �R���C�_�ǉ�
    mCollider = new ColliderComponent(this);
    mCollider->SetRadius(70.0f * GetScale());
    
}

// �A�N�^�X�V
void Player::UpdateActor(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    Actor::UpdateActor(deltaTime);
    // �Q�[���I�����Ă����瓮�����Ȃ�
    if (GetGame()->GetScene()->GetSceneName().compare("END") != 0)
    {
        // �v���C���[���ړ�������
        float texwidth = mTexWidth;
        float texheight = mTexHeight;
        Vector2 pos = GetPosition();

        pos.x += mRightMove * deltaTime;
        pos.y += mDownMove * deltaTime;
        if (pos.x < texwidth / 2)
        {
            pos.x = texwidth / 2;
        }
        else if (pos.x > Game::ScreenWidth - texwidth / 2)
        {
            pos.x = Game::ScreenWidth - texwidth / 2;
        }
        if (pos.y < texheight / 2)
        {
            pos.y = texheight / 2;
        }
        else if (pos.y > Game::ScreenHeight - texheight / 2)
        {
            pos.y = Game::ScreenHeight - texheight / 2;
        }
        SetPosition(pos);
    }


    /*
    // �G�l�~�[�ƏՓ˂����玀�S
    for (auto enemy : GetGame()->GetEnemies())
    {
        if (Intersect(*mCollider, *(enemy->GetCollider())))
        {
            // �Q�[���I��
            GetGame()->SetNextScene(new EndScene(GetGame()));
            SetState(EDead);
            // �F���D�̈ʒu�Ŕ����G�t�F�N�g
            auto* bomb = new BombEffect(GetGame());
            bomb->SetPosition(Vector2(GetPosition()));
            return;
        }
    }
    */
    

    // �~�T�C�������Ԋu���J����
    if (!mIsCanShot)
    {
        mDeltaShotTime += deltaTime;
        if (mDeltaShotTime > CanShotTime)
        {
            mIsCanShot = true;
            mDeltaShotTime = 0.0f;
        }
    }
    
}

// �L�[�{�[�h����
void Player::ProcessKeyboard(const uint8_t* state)
{
    mRightMove = 0.0f;
    mDownMove = 0.0f;
    // �L�[���͂ŏ㉺���E�Ɉړ�������
    if (state[SDL_SCANCODE_D])
    {
        mRightMove += PlayerSpeed;
    }
    if (state[SDL_SCANCODE_A])
    {
        mRightMove -= PlayerSpeed;
    }
    if (state[SDL_SCANCODE_S])
    {
        mDownMove += PlayerSpeed;
    }
    if (state[SDL_SCANCODE_W])
    {
        mDownMove -= PlayerSpeed;
    }

    if (state[SDL_SCANCODE_UP]) {
        mDownMove -= PlayerSpeed;
    }
    if (state[SDL_SCANCODE_LEFT]) {
        mRightMove -= PlayerSpeed;
    }
    if (state[SDL_SCANCODE_DOWN]) {
        mDownMove += PlayerSpeed;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        mRightMove += PlayerSpeed;
    }

    
    // �~�T�C��������
    if (state[SDL_SCANCODE_K])
    {
        if (mIsCanShot)
        {
            // ���Ԋu���J���邽�߃t���O��ύX
            mIsCanShot = false;
            mDeltaShotTime = 0.0f;
            // �~�T�C������
            auto* missile = new Missile(GetGame());
            Vector2 pos = GetPosition();
            missile->SetPosition(Vector2(pos.x, pos.y - 30.0f));
        }
    }
    
}
#include "Enemy.h"
#include <cmath>
#include <iostream>
#include "Game.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"

Enemy::Enemy(Game* game)
    :Actor(game)
    , mEnemyMoveType(STRAIGHT)
    , mEnemySpeed(150.0f)
    , mTimeCount(0.0f)
    , mEnemyShakeHeight(5.0f)
    , mEnemyShakeWidth(5.0f)
    , mWaitTime(0.0f)
{
    // �X�v���C�g�ݒ�
    auto* sprite = new SpriteComponent(this);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "pi-.png"));
    // �R���C�_�ǉ�
    mCollider = new ColliderComponent(this);
    mCollider->SetRadius(50.0f * GetScale());
    // �G�l�~�[�ǉ�
    game->AddEnemy(this);
}

Enemy::~Enemy()
{
    // �G�l�~�[�폜
    GetGame()->RemoveEnemy(this);
}

void Enemy::UpdateActor(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    Actor::UpdateActor(deltaTime);

    // �ҋ@���ԕ��͑҂�
    mTimeCount++;
    if (mTimeCount < mWaitTime)
    {
        return;
    }

    // �ړ�����
    Vector2 pos = GetPosition();
    
    switch (mEnemyMoveType)
    {
    case STRAIGHT:
        pos.x -= mEnemySpeed * deltaTime;
        break;
    case SHAKE:
        pos.x -= mEnemySpeed * deltaTime;
        pos.y = mInitPosition->y + (sinf(mTimeCount / 10.0f) * mEnemyShakeHeight);
        break;
    default:
        break;
    }
    
    /*
    // ��ʊO�ɏo����Q�[���I�[�o�[
    if (pos.y >= Game::ScreenHeight)
    {
        SetState(EDead);
        GetGame()->SetNextScene(new EndScene(GetGame()));
    }
    */

    SetPosition(pos);
}

void Enemy::SetPosition(const Vector2& pos)
{
    // �ʒu��ێ�����
    mInitPosition = new Vector2(pos.x, pos.y);
    Actor::SetPosition(pos);
}

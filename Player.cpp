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
    
    // スプライト設定
    auto* sprite = new SpriteComponent(this);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "player.png"));
    mTexWidth = sprite->GetTexWidth();
    mTexHeight = sprite->GetTexHeight();
    // コライダ追加
    mCollider = new ColliderComponent(this);
    mCollider->SetRadius(70.0f * GetScale());
    
}

// アクタ更新
void Player::UpdateActor(float deltaTime)
{
    // 親のメソッド呼び出し
    Actor::UpdateActor(deltaTime);
    // ゲーム終了していたら動かさない
    if (GetGame()->GetScene()->GetSceneName().compare("END") != 0)
    {
        // プレイヤーを移動させる
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
    // エネミーと衝突したら死亡
    for (auto enemy : GetGame()->GetEnemies())
    {
        if (Intersect(*mCollider, *(enemy->GetCollider())))
        {
            // ゲーム終了
            GetGame()->SetNextScene(new EndScene(GetGame()));
            SetState(EDead);
            // 宇宙船の位置で爆発エフェクト
            auto* bomb = new BombEffect(GetGame());
            bomb->SetPosition(Vector2(GetPosition()));
            return;
        }
    }
    */
    

    // ミサイルを撃つ間隔を開ける
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

// キーボード入力
void Player::ProcessKeyboard(const uint8_t* state)
{
    mRightMove = 0.0f;
    mDownMove = 0.0f;
    // キー入力で上下左右に移動させる
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

    
    // ミサイルを撃つ
    if (state[SDL_SCANCODE_K])
    {
        if (mIsCanShot)
        {
            // 撃つ間隔を開けるためフラグを変更
            mIsCanShot = false;
            mDeltaShotTime = 0.0f;
            // ミサイル生成
            auto* missile = new Missile(GetGame());
            Vector2 pos = GetPosition();
            missile->SetPosition(Vector2(pos.x, pos.y - 30.0f));
        }
    }
    
}
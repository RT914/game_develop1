#include <Eigen/Dense>
#include <stdio.h>
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Scene.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"

Player::Player(Game* game)
    :Actor(game)
    , mRightMove(0.0f)
    , mDownMove(0.0f)
    , mIsCanShot(false)
    , mDeltaShotTime(0.0f)
{
    
    // スプライト設定
    auto* sprite = new SpriteComponent(this);
    //sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "ship.png"));
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
        float scale = 30 * GetScale();
        Vector2 pos = GetPosition();

        std::cout << pos.x << std::endl;

        pos.x += mRightMove * deltaTime;
        pos.y += mDownMove * deltaTime;
        if (pos.x < 0.0f)
        {
            pos.x = 0.0f;
        }
        else if (pos.x > Game::ScreenWidth - scale)
        {
            pos.x = Game::ScreenWidth - scale;
        }
        if (pos.y < 0.0f)
        {
            pos.y = 0.0f;
        }
        else if (pos.y > Game::ScreenHeight - scale)
        {
            pos.y = Game::ScreenHeight - scale;
        }
        SetPosition(pos);
    }

    /*
    // ゲーム終了していたら動かさない
    if (GetGame()->GetScene()->GetSceneName().compare("END") != 0)
    {
        // プレイヤーを移動させる
        Vector2 pos = GetPosition();
        pos.x += mRightMove * deltaTime;
        pos.y += mDownMove * deltaTime;
        if (pos.x < 25.0f)
        {
            pos.x = 25.0f;
        }
        else if (pos.x > Game::ScreenWidth - 25.0f)
        {
            pos.x = Game::ScreenWidth - 25.0f;
        }
        if (pos.y < 25.0f)
        {
            pos.y = 25.0f;
        }
        else if (pos.y > Game::ScreenHeight - 25.0f)
        {
            pos.y = Game::ScreenHeight - 25.0f;
        }
        SetPosition(pos);
    }
    */

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
    */
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

    /*
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
    */
}
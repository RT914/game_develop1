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
    // スプライト設定
    auto* sprite = new SpriteComponent(this);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "pi-.png"));
    // コライダ追加
    mCollider = new ColliderComponent(this);
    mCollider->SetRadius(50.0f * GetScale());
    // エネミー追加
    game->AddEnemy(this);
}

Enemy::~Enemy()
{
    // エネミー削除
    GetGame()->RemoveEnemy(this);
}

void Enemy::UpdateActor(float deltaTime)
{
    // 親のメソッド呼び出し
    Actor::UpdateActor(deltaTime);

    // 待機時間分は待つ
    mTimeCount++;
    if (mTimeCount < mWaitTime)
    {
        return;
    }

    // 移動処理
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
    // 画面外に出たらゲームオーバー
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
    // 位置を保持する
    mInitPosition = new Vector2(pos.x, pos.y);
    Actor::SetPosition(pos);
}

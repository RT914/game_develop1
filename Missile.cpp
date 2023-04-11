#include "Missile.h"
#include "Enemy.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"
#include "ExplosionEffect.h"

Missile::Missile(class Game* game)
    :Actor(game)
{
    // スプライト追加
    auto* sprite = new SpriteComponent(this, 90);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "kakinotane.png")); // ミサイルの画像をセット
    // コライダ追加
    mCollider = new ColliderComponent(this);
    mCollider->SetRadius(50.0f * GetScale());
}

// アクタ更新
void Missile::UpdateActor(float deltaTime)
{
    // 親のメソッド呼び出し
    Actor::UpdateActor(deltaTime);
    // ミサイルを移動させる
    Vector2 pos = GetPosition();
    pos.x += mMissileSpeed * deltaTime;
    
    // 画面上部で破棄
    if (pos.y <= 50.0f)
    {
        SetState(EDead);
    }
    SetPosition(pos);

    
    // エネミーとの衝突判定
    for (auto enemy : GetGame()->GetEnemies())
    {
        if (Intersect(*mCollider, *(enemy->GetCollider())))
        {
            SetState(EDead);
            enemy->SetState(EDead);
            // エネミーの位置で爆発させる
            // enemy->GetScale();
            auto* explosioneffect = new ExplosionEffect(GetGame());
            explosioneffect->SetPosition(Vector2(enemy->GetPosition()));
            break;
        }
    }
    
}
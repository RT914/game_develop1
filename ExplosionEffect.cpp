#include "ExplosionEffect.h"
#include "Game.h"
#include "SpriteComponent.h"

ExplosionEffect::ExplosionEffect(class Game* game, int num)
    :Actor(game)
    , mTimeCount(0.0f)
{
    // スプライト設定
    auto* sprite = new SpriteComponent(this);
    if (num == 1) { // プレイヤー
        sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "boom.png"));
    }
    else if (num == 2) { // ピーナッツと柿の種
        sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "kp_explosion.png"));
    }
    else {
        sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "kp_explosion.png"));
    }
    
    // 最初は大きさ0にする
    SetScale(0.0f);
}

void ExplosionEffect::UpdateActor(float deltaTime)
{
    // 親のメソッド呼び出し
    Actor::UpdateActor(deltaTime);
    // 徐々に大きくする
    float changeScale = mTimeCount / DisplayTime * 3.0f;
    if (changeScale > 1.0f)
    {
        changeScale = 1.0f;
    }
    SetScale(changeScale);
    // 表示時間を過ぎたら破棄
    mTimeCount += deltaTime;
    if (mTimeCount >= DisplayTime)
    {
        SetState(EDead);
    }
}
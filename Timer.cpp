#include "Timer.h"
#include "Game.h"
#include "SpriteComponent.h"
#include <iostream>


Timer::Timer(class Game* game) 
    :Actor(game)
    ,mStart(0), mEnd(0), mDifftime(0)
{
    mSprite = new SpriteComponent(this);
    
}

// アクタ更新
void Timer::UpdateActor(float deltaTime)
{
    // 親のメソッド呼び出し
    Actor::UpdateActor(deltaTime);

    // ゲーム終了していたら動かさない
    if (GetGame()->GetScene()->GetSceneName().compare("END") != 0)
    {
        mSprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
        std::cout << GetGame()->GetTimer()->GetDiffTime() << std::endl;
    }
}

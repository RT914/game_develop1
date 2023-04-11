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

// �A�N�^�X�V
void Timer::UpdateActor(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    Actor::UpdateActor(deltaTime);

    // �Q�[���I�����Ă����瓮�����Ȃ�
    if (GetGame()->GetScene()->GetSceneName().compare("END") != 0)
    {
        mSprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
        std::cout << GetGame()->GetTimer()->GetDiffTime() << std::endl;
    }
}

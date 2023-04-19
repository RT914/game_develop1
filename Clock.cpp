#include "Clock.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Timer.h"
#include <iostream>


Clock::Clock(class Game* game)
    :Actor(game)
    ,mSprite(nullptr)
{
    // �X�v���C�g�ݒ�
    auto* sprite = new SpriteComponent(this);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
    SetSprite(sprite);
    game->AddClock(this);

}

// �A�N�^�X�V
void Clock::UpdateActor(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    Actor::UpdateActor(deltaTime);

    // �Q�[���I�����Ă����瓮�����Ȃ�
    if (GetGame()->GetScene()->GetSceneName().compare("END") != 0)
    {
        // auto* sprite = GetSprite();

        int difftime = GetGame()->GetTimer()->GetDiffTime();
        std::vector<class Clock*> clocks = GetGame()->mClocks;

        int n1 = 0;
        int n2 = 0;

        int minute_1 = 0;
        int minute_2 = 0;

        int second_1 = 0;
        int second_2 = 0;

        n1 = difftime / 1000 / 60;
        std::cout << difftime << std::endl;
        minute_1 = n1 % 60 / 10;
        minute_2 = n1 % 10;

        n2 = difftime / 1000;
        second_1 = n2 % 60 / 10;
        second_2 = n2 % 10;

        switch (minute_1) {
            case 0:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
                break;
            case 1:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
                break;
            case 2:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "2.png"));
                break;
            case 3:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "3.png"));
                break;
            case 4:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "4.png"));
                break;
            case 5:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "5.png"));
                break;
            case 6:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "6.png"));
                break;
            case 7:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "7.png"));
                break;
            case 8:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "8.png"));
                break;
            case 9:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "9.png"));
                break;
            default:
                clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
                break;
        }

        switch (minute_2) {
        case 0:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
            break;
        case 1:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
            break;
        case 2:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "2.png"));
            break;
        case 3:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "3.png"));
            break;
        case 4:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "4.png"));
            break;
        case 5:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "5.png"));
            break;
        case 6:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "6.png"));
            break;
        case 7:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "7.png"));
            break;
        case 8:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "8.png"));
            break;
        case 9:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "9.png"));
            break;
        default:
            clocks[1]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
            break;
        }

        switch (second_1) {
        case 0:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
            break;
        case 1:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
            break;
        case 2:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "2.png"));
            break;
        case 3:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "3.png"));
            break;
        case 4:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "4.png"));
            break;
        case 5:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "5.png"));
            break;
        case 6:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "6.png"));
            break;
        case 7:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "7.png"));
            break;
        case 8:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "8.png"));
            break;
        case 9:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "9.png"));
            break;
        default:
            clocks[2]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
            break;
        }

        switch (second_2) {
        case 0:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
            break;
        case 1:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
            break;
        case 2:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "2.png"));
            break;
        case 3:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "3.png"));
            break;
        case 4:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "4.png"));
            break;
        case 5:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "5.png"));
            break;
        case 6:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "6.png"));
            break;
        case 7:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "7.png"));
            break;
        case 8:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "8.png"));
            break;
        case 9:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "9.png"));
            break;
        default:
            clocks[3]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "0.png"));
            break;
        }

        //clocks[0]->GetSprite()->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
        // sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "1.png"));
    }
}
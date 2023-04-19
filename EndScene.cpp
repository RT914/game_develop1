#include "EndScene.h"
#include "ReadyScene.h"
#include "Game.h"
#include "Actor.h"
#include "Enemy.h"
#include "Player.h"
#include "SpriteComponent.h"

EndScene::EndScene(class Game* game)
    :Scene(game)
{
}

EndScene::~EndScene()
{
}

void EndScene::Start()
{
    // �I�����b�Z�[�W�̍쐬
    mEndMsg = new Actor(mGame);
    mEndMsg->SetPosition(Vector2(mGame->ScreenWidth / 2, mGame->ScreenHeight / 2));
    auto* endMsgSprite = new SpriteComponent(mEndMsg, 200);
    endMsgSprite->SetTexture(
        mGame->LoadTexture(mGame->GetAssetsPath() + (mGame->GetGameClear() ? "msg_clear.png" : "msg_over.png")));
}

void EndScene::Update(float deltaTime)
{
}

void EndScene::ProcessInput(const Uint8* state)
{
    /*
    // �X�y�[�X���G���^�[�����ŊJ�n�V�[���ɑJ��
    if (state[SDL_SCANCODE_SPACE] || state[SDL_SCANCODE_RETURN])
    {
        mGame->SetNextScene(new ReadyScene(mGame));
        mEndMsg->SetState(Actor::EDead);
        // �F���D�ƃG�l�~�[��j��
        std::vector<class Actor*> actors = mGame->GetActors();
        Actor* ship = mGame->GetShip();
        auto iter = std::find(actors.begin(), actors.end(), ship);
        if (iter != actors.end())
        {
            ship->SetState(Actor::EDead);
        }
        for (auto enemy : mGame->GetEnemies())
        {
            enemy->SetState(Actor::EDead);
        }
    }
    */
}

std::string const EndScene::GetSceneName()
{
    return "END";
}
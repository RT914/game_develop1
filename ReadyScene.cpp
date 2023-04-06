#include "ReadyScene.h"
#include "Scene.h"
#include "Game.h"
#include "Actor.h"
#include "SpriteComponent.h"
#include "GameScene.h"
#include "Player.h"

ReadyScene::ReadyScene(class Game* game)
    :Scene(game)
{
}

ReadyScene::~ReadyScene()
{
}

void ReadyScene::Start()
{
    // �N���A�t���O��������
    mGame->SetGameClear(false);
    // �J�n���b�Z�[�W�̍쐬
    mStartMsg = new Actor(mGame);
    mStartMsg->SetPosition(Vector2(mGame->ScreenWidth / 2, mGame->ScreenHeight / 2));
    auto* startMsgSprite = new SpriteComponent(mStartMsg, 200);
    startMsgSprite->SetTexture(mGame->LoadTexture(mGame->GetAssetsPath() + "msg_start.png"));
    // �v���[���[�̍쐬
    Player* player = new Player(mGame);
    player->SetPosition(Vector2(mGame->ScreenWidth / 2, mGame->ScreenHeight - 200.0f));
    mGame->SetPlayer(player);
}

void ReadyScene::Update(float deltaTime)
{
}

void ReadyScene::ProcessInput(const Uint8* state)
{
    // �X�y�[�X���G���^�[�����ŃQ�[���V�[���ɑJ��
    if (state[SDL_SCANCODE_SPACE] || state[SDL_SCANCODE_RETURN])
    {
        mGame->SetNextScene(new GameScene(mGame));
        mStartMsg->SetState(Actor::EDead);
    }
}

std::string const ReadyScene::GetSceneName()
{
    return "READY";
}
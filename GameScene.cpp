#include "GameScene.h"
#include "Game.h"
#include "Math.h"
#include "Player.h"
#include "Enemy.h"

GameScene::GameScene(class Game* game)
    :Scene(game)
{
}

GameScene::~GameScene()
{
}

void GameScene::Start()
{
    
    // �G�l�~�[�������_���쐬
    for (int i = 0; i < 300; i++)
    {
        auto* enemy = new Enemy(mGame);
        // enemy->SetPosition(Vector2(Math::GetRand(100.0f, mGame->ScreenWidth - 100.0f), -100.0f)); // �G�̏����ʒu�ݒ�i�c�j
        enemy->SetPosition(Vector2(mGame->ScreenWidth + 100.0f, Math::GetRand(100.0f, mGame->ScreenHeight - 100.0f))); // �G�̏����ʒu�ݒ�i���j
        enemy->SetEnemySpeed(Math::GetRand(300.0f, 550.0f));
        enemy->SetScale(Math::GetRand(0.5f, 1.5f));
        // ���C���Ƃɗh�炷
        if (i % 2 == 0)
        {
            enemy->SetEnemyMoveType(Enemy::SHAKE);
            enemy->SetEnemyShakeWidth(Math::GetRand(5.0f, 15.0f));
        }
        // ���C��������
        enemy->SetWaitTime(i / 3 * Math::GetRand(80.0f, 100.0f));
    }
    
    
}

void GameScene::Update(float deltaTime)
{
    /*
    // �G�l�~�[��S�����j������Q�[���N���A
    if (mGame->GetEnemies().empty())
    {
        mGame->SetGameClear(true);
        mGame->SetNextScene(new EndScene(mGame));
    }
    */
}

void GameScene::ProcessInput(const Uint8* state)
{
    // �v���C���[�̃L�[���͑���
    mGame->GetPlayer()->ProcessKeyboard(state);
}

std::string const GameScene::GetSceneName()
{
    return "GAME";
}

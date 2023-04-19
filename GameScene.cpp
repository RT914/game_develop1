#include <iostream>
#include <vector>
#include "GameScene.h"
#include "Game.h"
#include "Math.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include "Clock.h"

GameScene::GameScene(class Game* game)
    :Scene(game)
{
}

GameScene::~GameScene()
{
} 

void GameScene::Start()
{
    // �^�C�}�[�N���X�̍쐬
    Timer* timer = new Timer(mGame);
    mGame->SetTimer(timer);

    // �J�n���Ԃ��擾
    int start = SDL_GetTicks64();
    // std::cout << start << std::endl;
    mGame->GetTimer()->SetStartTime(start);

    // �N���b�N�N���X�̍쐬 for���ł��ł��邩��
    Clock* clock1 = new Clock(mGame);
    Clock* clock2 = new Clock(mGame);
    Clock* clock3 = new Clock(mGame);
    Clock* clock4 = new Clock(mGame);
    // Clock* clock5 = new Clock(mGame);
    // Clock* clock6 = new Clock(mGame);

    clock1->SetPosition(Vector2(100.0f, 100.0f));
    clock2->SetPosition(Vector2(200.0f, 100.0f));
    clock3->SetPosition(Vector2(300.0f, 100.0f));
    clock4->SetPosition(Vector2(400.0f, 100.0f));
    // clock5->SetPosition(Vector2(500.0f, 100.0f));
    // clock6->SetPosition(Vector2(600.0f, 100.0f));

    // �G�l�~�[�������_���쐬
    for (int i = 0; i < 30000; i++)
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
        enemy->SetWaitTime(i / 3 * Math::GetRand(80.0f, 100.0f) * 0.35);
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

    // ���Ԃ̍X�V
    int end = SDL_GetTicks64();
    // �Q�[���J�n����̌o�ߎ��Ԃ̎擾
    int diff_time = end - ( mGame->GetTimer()->GetStartTime() );
    mGame->GetTimer()->SetDiffTime(diff_time);
    // std::cout << diff_time << std::endl;
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

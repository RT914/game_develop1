#include <iostream>
#include "GameScene.h"
#include "Game.h"
#include "Math.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"

GameScene::GameScene(class Game* game)
    :Scene(game)
{
}

GameScene::~GameScene()
{
} 

void GameScene::Start()
{
    // タイマークラスの作成
    Timer* timer = new Timer(mGame);
    mGame->SetTimer(timer);

    // 開始時間を取得
    int start = SDL_GetTicks64();
    // std::cout << start << std::endl;
    mGame->GetTimer()->SetStartTime(start);

    // エネミーをランダム作成
    for (int i = 0; i < 30000; i++)
    {
        auto* enemy = new Enemy(mGame);
        // enemy->SetPosition(Vector2(Math::GetRand(100.0f, mGame->ScreenWidth - 100.0f), -100.0f)); // 敵の初期位置設定（縦）
        enemy->SetPosition(Vector2(mGame->ScreenWidth + 100.0f, Math::GetRand(100.0f, mGame->ScreenHeight - 100.0f))); // 敵の初期位置設定（横）
        enemy->SetEnemySpeed(Math::GetRand(300.0f, 550.0f));
        enemy->SetScale(Math::GetRand(0.5f, 1.5f));
        // 数匹ごとに揺らす
        if (i % 2 == 0)
        {
            enemy->SetEnemyMoveType(Enemy::SHAKE);
            enemy->SetEnemyShakeWidth(Math::GetRand(5.0f, 15.0f));
        }
        // 数匹ずつ動かす
        enemy->SetWaitTime(i / 3 * Math::GetRand(80.0f, 100.0f) * 0.35);
    }
    
    
}

void GameScene::Update(float deltaTime)
{
    /*
    // エネミーを全部撃破したらゲームクリア
    if (mGame->GetEnemies().empty())
    {
        mGame->SetGameClear(true);
        mGame->SetNextScene(new EndScene(mGame));
    }
    */

    // 時間の更新
    int end = SDL_GetTicks64();
    // ゲーム開始からの経過時間の取得
    int diff_time = end - ( mGame->GetTimer()->GetStartTime() );
    mGame->GetTimer()->SetDiffTime(diff_time);
    // std::cout << diff_time << std::endl;
}

void GameScene::ProcessInput(const Uint8* state)
{
    // プレイヤーのキー入力操作
    mGame->GetPlayer()->ProcessKeyboard(state);
}

std::string const GameScene::GetSceneName()
{
    return "GAME";
}

#include <iostream>
#include <Eigen/Dense>
#include <time.h>
#include "SDL_image.h"
#include <vector>
#include "Object.h"
#include "Player.h"
#include "Ball.h"
#include "Game.h"
#include "Math.h"
#include "SpriteComponent.h"
#include "ReadyScene.h"
#include "GameScene.h"
#include "Actor.h"
#include "Enemy.h"
#include "ScrollSpriteComponent.h"

std::vector<int> inputkeyboard{0, 0};
std::vector<Ball> ball_structs;
Object object = createOblect();
int window_length[2] = { Game::ScreenWidth, Game::ScreenHeight};
static const int number_of_ball = object.balls.size();

Game::Game() :mWindow(nullptr), mRenderer(nullptr), mTicksCount(0), mIsRunning(true), mUpdatingActors(false), mGameClear(false)
{

}

// ゲームの初期化
bool Game::Initialize() {

	// SDL初期化
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) {
		SDL_Log("SDLを初期化できません : %s", SDL_GetError());
		return false;
	}

	// SDLウィンドウを作成
	mWindow = SDL_CreateWindow(
		"ball avoidance game", // ウィンドウのタイトル
		-200, // ウィンドウ左上隅のx座標
		50, // ウィンドウ左上隅のy座標
		ScreenWidth, // ウィンドウの幅(width)
		ScreenHeight, // ウィンドウの高さ(height)
		0 // フラグ(設定しない時は0)
	);

	if (!mWindow) {
		SDL_Log("ウィンドウの作成に失敗しました : %s", SDL_GetError());
		return false;
	}

	// SDLレンダラーを作成
	mRenderer = SDL_CreateRenderer(
		mWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	// シーン初期化
	InitScene();

	return true;
}

// シーン初期化処理（一度だけ呼ばれる）
void Game::InitScene()
{
	// 背景の作成
	// 背景をスクロールさせる処理
	auto* bgBack = new Actor(this);
	bgBack->SetPosition(Vector2(ScreenWidth / 2, ScreenHeight / 2));
	auto* bgBackSprite = new ScrollSpriteComponent(bgBack, 10);
	bgBackSprite->SetTexture(LoadTexture(GetAssetsPath() + "sky.jpg"));
	//bgBackSprite->SetTexture(LoadTexture(GetAssetsPath() + "sky.jpg"));
	bgBackSprite->SetScrollSpeedX(100.0f); // 速度：100
	// bgBackSprite->SetScrollSpeedY(100.0f); // 速度：100

	/*
	auto* bgFront = new Actor(this);
	bgFront->SetPosition(Vector2(ScreenWidth / 2, ScreenHeight / 2));
	auto* bgFrontSprite = new ScrollSpriteComponent(bgFront, 20);
	bgFrontSprite->SetTexture(LoadTexture(GetAssetsPath() + "bubble.png"));
	bgFrontSprite->SetScrollSpeedY(200.0f); // 速度：200
	*/
}

void Game::RunLoop() {

	// 開始シーンを設定
	mScene = new ReadyScene(this);
	mNextScene = mScene;
	StartScene();
	
	while (mIsRunning) 
	{
		// シーン更新処理
		UpdateScene();
		//cout << mScene->GetSceneName() << endl;
		if (mScene->GetSceneName().compare(mNextScene->GetSceneName()) != 0)
		{
			delete mScene;
			mScene = mNextScene;
			StartScene();
		}
		
	}
	SDL_Delay(1000); //1秒遅延
}

// シャットダウン
void Game::Shutdown() {
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

// アクタ追加処理
void Game::AddActor(Actor* actor)
{
	// アクタ更新中ならPendingに格納
	mUpdatingActors
		? mPendingActors.emplace_back(actor)
		: mActors.emplace_back(actor);
}

// シーン開始処理
void Game::StartScene()
{
	mScene->Start();
}

// シーン更新処理
void Game::UpdateScene()
{
	ProcessInput();

	//printf("chech\n");

	//1frame=16ms
	//前のフレームから16msが経過するまで待つ
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

	//ms→s
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

	//deltatimeを最大値で制限する
	if (deltaTime > 0.05f) {
		deltaTime = 0.05f;
	}

	mTicksCount = SDL_GetTicks();

	
	// ここ重要かもしれないから理解したい
	// アクタ更新処理
	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		actor->Update(deltaTime);
	}
	mUpdatingActors = false;

	// 待機中のアクタを追加
	for (auto pending : mPendingActors)
	{
		mActors.emplace_back(pending);
	}
	mPendingActors.clear();

	// 各シーンの更新処理
	mScene->Update(deltaTime);

	// 死亡したアクタを破棄
	std::vector<Actor*> deadActors;
	for (auto actor : mActors)
	{
		if (actor->GetState() == Actor::EDead)
		{
			deadActors.emplace_back(actor);
		}
	}
	for (auto actor : deadActors)
	{
		delete actor;
	}
	
	

	/*
	//玉とplayerの衝突判定
	for (int i = 0; i < object.balls.size(); i++) {
		if ((player.position.x() - player.size / 2 > object.balls[i].position.x() - player.size) && (player.position.x() - player.size / 2 < object.balls[i].position.x() + object.balls[i].size)) {
			if ((player.position.y() - player.size / 2 > object.balls[i].position.y() - player.size) && (player.position.y() - player.size / 2 < object.balls[i].position.y() + object.balls[i].size)) {

				//衝突検知
				mIsRunning = false;

			}
		}
	}

	for (int i = 0; i < 2; i++) {
		player.position[i] += inputkeyboard[i] * 300.0f * deltaTime;

		for (int j = 0; j < object.balls.size(); j++) {
			object.balls[j].position[i] += object.balls[j].velocity[i] * 10.0f * deltaTime;

			//玉の壁反射
			if (object.balls[j].position[i] <= 0) {
				object.balls[j].velocity[i] *= -1;
			}

			if (object.balls[j].position[i] >= window_length[i]) {
				object.balls[j].velocity[i] *= -1;
			}

		}
	}

	//画面外への移動禁止
	if (player.position.x() <= 0 + player.size / 2) { player.position.x() = player.size / 2; }

	if (player.position.y() <= 0 + player.size / 2) { player.position.y() = player.size / 2; }

	if (player.position.x() >= ScreenWidth - player.size / 2) { player.position.x() = ScreenWidth - player.size / 2; }

	if (player.position.y() >= ScreenHeight - player.size / 2) { player.position.y() = ScreenHeight - player.size / 2; }
	*/

	GenerateOutput();
}

// アクタ削除処理
void Game::RemoveActor(Actor* actor)
{
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		mPendingActors.erase(iter);
	}
	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		mActors.erase(iter);
	}
}

// 描画中のスプライト追加処理
void Game::AddSprite(SpriteComponent* sprite)
{
	// 描画順にソートして追加
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (; iter != mSprites.end(); ++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}
	mSprites.insert(iter, sprite);
}

// 描画中のスプライト削除処理
void Game::RemoveSprite(SpriteComponent* sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	mSprites.erase(iter);
}

// エネミー追加
void Game::AddEnemy(Enemy* enemy)
{
	mEnemies.emplace_back(enemy);
}

// エネミー削除
void Game::RemoveEnemy(Enemy* enemy)
{
	auto iter = std::find(mEnemies.begin(), mEnemies.end(), enemy);
	if (iter != mEnemies.end())
	{
		mEnemies.erase(iter);
	}
}

// クロック追加
void Game::AddClock(Clock* clock)
{
	mClocks.emplace_back(clock);
}

void Game::ProcessInput() {
	SDL_Event event;
	// キューにイベントがあれば繰り返す
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			mIsRunning = false;
			break;
		default:
			break;
		}
	}

	// キー入力を検知
	// ESCAPE入力されると終了
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}

	mScene->ProcessInput(state);

}

void Game::GenerateOutput() {

	// 描画色を青色に設定
	SDL_SetRenderDrawColor(
		mRenderer,
		0, 176, 255, 255 // (R,G,B,A)
	);

	// バックバッファを青色で塗りつぶす
	SDL_RenderClear(mRenderer);

	// スプライトを描画
	for (auto sprite : mSprites)
	{
		sprite->Draw(mRenderer);
	}

	// 消すかも
	/*
	// 描画色を白色に設定
	SDL_SetRenderDrawColor(mRenderer, 255, 100, 5, 255);

	SDL_Rect player1{
		static_cast<int>(player.position.x() - player.size / 2),
		static_cast<int>(player.position.y() - player.size / 2),
		player.size,
		player.size
	};

	SDL_RenderFillRect(mRenderer, &player1);

	SDL_SetRenderDrawColor(mRenderer, 0, 0, 100, 255);

	SDL_Rect player2{
		static_cast<int>(player.position.x() - player.size / 2) + 2,
		static_cast<int>(player.position.y() - player.size / 2) + 2,
		player.size - 4,
		player.size - 4
	};

	SDL_RenderFillRect(mRenderer, &player2);


	for (int i = 0; i < object.balls.size(); i++) {
		SDL_SetRenderDrawColor(mRenderer, rand() % 255, rand() % 255, rand() % 255, rand() % 255);
		SDL_Rect ball{
			object.balls[i].position.x(),
			object.balls[i].position.y(),
			object.balls[i].size,
			object.balls[i].size
		};

		SDL_RenderFillRect(mRenderer, &ball);
	}
	*/

	// バックバッファとフロントバッファを入れ替え
	SDL_RenderPresent(mRenderer);
}

// ファイル名からテクスチャをロードする
SDL_Texture* Game::LoadTexture(const std::string& fileName)
{
	SDL_Texture* tex = nullptr;
	auto iter = mCachedTextures.find(fileName);
	if (iter != mCachedTextures.end())
	{
		// キャッシュ済なら変数から取得
		tex = iter->second;
	}
	else
	{
		// テクスチャをロードする
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf)
		{
			SDL_Log("Error load texture file %s", fileName.c_str());
			return nullptr;
		}
		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Error convert surface to texture %s", fileName.c_str());
			return nullptr;
		}
		// 変数にキャッシュする
		mCachedTextures.emplace(fileName.c_str(), tex);
	}
	return tex;
}
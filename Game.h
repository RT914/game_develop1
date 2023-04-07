#ifndef _GAME_H_
#define _GAME_H_

#include <Eigen/Dense>
#include <vector>
#include <unordered_map>
#include <string>
#include "SDL.h"
#include "Scene.h"

class Game {
public:
	Game();
	//ゲームを初期化する
	bool Initialize();
	//ゲームオーバーまでゲームループを実行する
	void RunLoop();
	//ゲームをシャットダウンする
	void Shutdown();

	void AddActor(class Actor* actor);    // アクタ追加
	void RemoveActor(class Actor* actor); // アクタ削除

	void AddSprite(class SpriteComponent* sprite);    // 描画中のスプライトを追加
	void RemoveSprite(class SpriteComponent* sprite); // 描画中のスプライトを削除

	SDL_Texture* LoadTexture(const std::string& fileName); // テクスチャロード処理

	constexpr static const float ScreenWidth = 1024.0f;  // スクリーン横幅
	constexpr static const float ScreenHeight = 768.0f; // スクリーン縦幅

private:
	
	void InitScene();      // シーン初期化処理
	void StartScene();     // シーン開始処理
	void UpdateScene();    // シーン更新処理
	void ProcessInput();   // 入力検知 
	void GenerateOutput(); // 出力処理

	class Scene* mScene;     // 現在のシーン
	class Scene* mNextScene; // 遷移するシーン

	std::vector<class Actor*> mActors;            // アクタリスト
	std::vector<class Actor*> mPendingActors;     // 待機中のアクタリスト
	std::vector<class SpriteComponent*> mSprites; // 描画中のスプライトリスト
	std::unordered_map<std::string, SDL_Texture*> mCachedTextures; // キャッシュしたテクスチャリスト

	// 入力による移動距離
	Eigen::Vector2d move_distance;

	//SDLが作るウィンドウ
	SDL_Window* mWindow;

	//2D描画のためのレンダリング
	SDL_Renderer* mRenderer;

	// Number of ticks since start of game
	Uint32 mTicksCount;

	//ゲームの続行を支持する
	bool mIsRunning;

	// アクタ更新中か否か？
	bool mUpdatingActors;

	// ゲームをクリアしたか否か？
	bool mGameClear;

	// 画像パス
	const std::string AssetsPath = ""; // Mac + CLion

	// プレイヤー
	class Player* mPlayer;

public:
	Scene* GetNextScene() const { return mNextScene; }
	void SetNextScene(class Scene* scene) { mNextScene = scene; }
	void SetGameClear(const bool isClear) { mGameClear = isClear; }
	Scene* GetScene() const { return mScene; }
	void SetScene(class Scene* scene) { mScene = scene; }
	std::string GetAssetsPath() const { return AssetsPath; }
	void SetPlayer(class Player* player) { mPlayer = player; }
	Player* GetPlayer() const { return mPlayer; }
};

#endif

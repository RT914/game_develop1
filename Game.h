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
	//�Q�[��������������
	bool Initialize();
	//�Q�[���I�[�o�[�܂ŃQ�[�����[�v�����s����
	void RunLoop();
	//�Q�[�����V���b�g�_�E������
	void Shutdown();

	void AddActor(class Actor* actor);    // �A�N�^�ǉ�
	void RemoveActor(class Actor* actor); // �A�N�^�폜

	void AddSprite(class SpriteComponent* sprite);    // �`�撆�̃X�v���C�g��ǉ�
	void RemoveSprite(class SpriteComponent* sprite); // �`�撆�̃X�v���C�g���폜

	void AddEnemy(class Enemy* enemy);    // �G�l�~�[�ǉ�
	void RemoveEnemy(class Enemy* enemy); // �G�l�~�[�폜

	void AddClock(class Clock* clock); // �N���b�N�ǉ�

	SDL_Texture* LoadTexture(const std::string& fileName); // �e�N�X�`�����[�h����

	constexpr static const float ScreenWidth = 2048.0f;  // �X�N���[������
	constexpr static const float ScreenHeight = 768.0f; // �X�N���[���c��

private:
	
	void InitScene();      // �V�[������������
	void StartScene();     // �V�[���J�n����
	void UpdateScene();    // �V�[���X�V����
	void ProcessInput();   // ���͌��m 
	void GenerateOutput(); // �o�͏���

	class Scene* mScene;     // ���݂̃V�[��
	class Scene* mNextScene; // �J�ڂ���V�[��

	std::vector<class Actor*> mActors;            // �A�N�^���X�g
	std::vector<class Actor*> mPendingActors;     // �ҋ@���̃A�N�^���X�g
	std::vector<class SpriteComponent*> mSprites; // �`�撆�̃X�v���C�g���X�g
	std::unordered_map<std::string, SDL_Texture*> mCachedTextures; // �L���b�V�������e�N�X�`�����X�g

	// ���͂ɂ��ړ�����
	Eigen::Vector2d move_distance;

	//SDL�����E�B���h�E
	SDL_Window* mWindow;

	//2D�`��̂��߂̃����_�����O
	SDL_Renderer* mRenderer;

	// Number of ticks since start of game
	Uint32 mTicksCount;

	//�Q�[���̑��s���x������
	bool mIsRunning;

	// �A�N�^�X�V�����ۂ��H
	bool mUpdatingActors;

	// �Q�[�����N���A�������ۂ��H
	bool mGameClear;

	// �摜�p�X
	//const std::string AssetsPath = "";
	const std::string AssetsPath = "images\\"; // Win + VisualStudio

	class Player* mPlayer; // �v���C���[

	std::vector<class Enemy*> mEnemies; // �G�l�~�[�Q

	class Timer* mTimer; // �^�C�}�[

public:
	std::vector<class Clock*> mClocks; // �N���b�N�Q
	Scene* GetNextScene() const { return mNextScene; }
	void SetNextScene(class Scene* scene) { mNextScene = scene; }
	void SetGameClear(const bool isClear) { mGameClear = isClear; }
	bool GetGameClear() const { return mGameClear; }
	Scene* GetScene() const { return mScene; }
	void SetScene(class Scene* scene) { mScene = scene; }
	std::vector<class Enemy*> GetEnemies() { return mEnemies; }
	std::vector<class Clock*> GetClocks() { return mClocks; }
	std::string GetAssetsPath() const { return AssetsPath; }
	void SetPlayer(class Player* player) { mPlayer = player; }
	Player* GetPlayer() const { return mPlayer; }
	void SetTimer(class Timer* timer) { mTimer = timer; }
	Timer* GetTimer() const { return mTimer; }
};

#endif

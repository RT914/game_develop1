#ifndef _READYSCENE_H_
#define _READYSCENE_H_

#include "Scene.h"

// �������V�[���N���X
class ReadyScene : public Scene {
public:
    ReadyScene(class Game* game);
    ~ReadyScene();
    void Start() override;
    void Update(float deltaTime) override;
    void ProcessInput(const Uint8* state) override;
    std::string const GetSceneName() override;

private:
    class Actor* mStartMsg; // �J�n���b�Z�[�W

};

#endif
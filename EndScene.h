#pragma once
#include "Scene.h"

// �I���V�[���N���X
class EndScene : public Scene {
public:
    EndScene(class Game* game);
    ~EndScene();
    void Start() override;
    void Update(float deltaTime) override;
    void ProcessInput(const Uint8* state) override;
    std::string const GetSceneName() override;

private:
    class Actor* mEndMsg;   // �I�����b�Z�[�W

};

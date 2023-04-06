#ifndef _SCENE_H_
#define _SCENE_H_

#include "SDL_image.h"
#include "string"

// �V�[�����N���X
// *�e�V�[���͂��̃N���X���p������
class Scene
{
public:
    Scene(class Game* game);
    virtual ~Scene();
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void ProcessInput(const Uint8* state);
    virtual std::string const GetSceneName();

protected:
    class Game* mGame;

};

#endif

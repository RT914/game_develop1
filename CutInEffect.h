#ifndef _CUTINEFFECT_H_
#define _CUTINEFFECT_H_

#include "SpriteComponent.h"
#include "Vector2.h"


// �A�N�^�N���X
// *�e�A�N�^�͂��̃N���X���p������
class CutInEffect : public SpriteComponent
{
public:
    CutInEffect(class Actor* actor, int drawOrder = 100);
    void Update(float deltatime) override;
    void Draw(SDL_Renderer* renderer) override;

private:
  

public:
   
};


#endif

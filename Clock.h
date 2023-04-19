#ifndef _ClOCK_H_
#define _CLOCK_H_

#include "Actor.h"

class Clock : public Actor {
public:
    Clock(class Game* game);
    void UpdateActor(float deltaTime) override; // �A�N�^�X�V
    void SetSprite(class SpriteComponent* sprite) { mSprite = sprite; }
    SpriteComponent* GetSprite() { return mSprite; }
private:
    // �X�v���C�g�ݒ�
    class SpriteComponent* mSprite;
};

#endif


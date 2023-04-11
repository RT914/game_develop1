#ifndef _TIMER_H_
#define _TIMER_H_

#include <time.h>
#include "Actor.h"

class Timer : public Actor{
public:
    Timer(class Game* game);
    void UpdateActor(float deltaTime) override; // �A�N�^�X�V
    void SetStartTime(int start) { mStart = start; }
    void SetEndTime(int end) { mEnd = end; }
    void SetDiffTime(int diff) { mDifftime = diff; }
    int GetStartTime() { return mStart; }
    int GetEndTime() { return mEnd; }
    int GetDiffTime() { return mDifftime; }
private:
    int mStart;
    int mEnd;
    int mDifftime;
    // �X�v���C�g�ݒ�
    class SpriteComponent* mSprite;
};

#endif


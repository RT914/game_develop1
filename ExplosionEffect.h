#pragma once
#include "Actor.h"

// �����G�t�F�N�g
class ExplosionEffect : public Actor {
public:
    ExplosionEffect(class Game* game, int num);
    void UpdateActor(float deltaTime) override;

private:
    float mTimeCount; // �o�ߎ���
    const float DisplayTime = 1.0f; // �\������
};


#pragma once
#include "Actor.h"

// �~�T�C���N���X
class Missile : public Actor {
public:
    Missile(class Game* game);
    void UpdateActor(float deltaTime) override; // �A�N�^�X�V

private:
    const float mMissileSpeed = 1000.0f; // �~�T�C���ړ����x
    class ColliderComponent* mCollider;  // �R���C�_
};


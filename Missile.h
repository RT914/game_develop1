#pragma once
#include "Actor.h"

// �~�T�C���N���X
class Missile : public Actor {
public:
    Missile(class Game* game, int num);
    void UpdateActor(float deltaTime) override; // �A�N�^�X�V

private:
    int MissileNum; // �~�T�C���̎��

    int GetMissileNum() { return MissileNum; }

    const float mMissileSpeed = 1000.0f; // �~�T�C���ړ����x
    class ColliderComponent* mCollider;  // �R���C�_
};


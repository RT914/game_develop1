#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <Eigen/Dense>
#include "Actor.h"

/*
struct Player {
	Player(Eigen::Vector2d& pos) : position(pos) {};

	Eigen::Vector2d position;
	int size = 4;
};
*/

// �ǉ���
class Player : public Actor {
public:
    Player(class Game* game);
    void UpdateActor(float deltaTime) override; // �A�N�^�X�V
    void ProcessKeyboard(const uint8_t* state); // �L�[�{�[�h����

private:
    float mRightMove; // �E�����ւ̈ړ���
    float mDownMove;  // �������ւ̈ړ���
    const float PlayerSpeed = 480.0f; // �ړ����x

    bool mIsCanShot;      // �~�T�C�������Ă邩�ǂ����H
    float mDeltaShotTime; // �~�T�C���������Ă���̎���
    const float CanShotTime = 0.15f; // �~�T�C�������Ă�悤�ɂȂ�܂ł̊Ԋu

    class ColliderComponent* mCollider;  // �R���C�_
};

#endif

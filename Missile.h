#pragma once
#include "Actor.h"

// ミサイルクラス
class Missile : public Actor {
public:
    Missile(class Game* game, int num);
    void UpdateActor(float deltaTime) override; // アクタ更新

private:
    int MissileNum; // ミサイルの種類

    int GetMissileNum() { return MissileNum; }

    const float mMissileSpeed = 1000.0f; // ミサイル移動速度
    class ColliderComponent* mCollider;  // コライダ
};


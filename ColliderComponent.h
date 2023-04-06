#pragma once
#include "Component.h"
#include "Vector2.h"

// �R���C�_�R���|�[�l���g�N���X
// *�����_�ł͉~�R���C�_�̂�
class ColliderComponent : public Component
{
public:
    ColliderComponent(class Actor* actor);
    const Vector2& GetCenter() const;

private:
    float mRadius; // ���a

public:
    void SetRadius(float radius) { mRadius = radius; }
    float GetRadius() const;

};

// �Փ˔��菈��
bool Intersect(const ColliderComponent& a, const ColliderComponent& b);


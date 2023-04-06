#include "ColliderComponent.h"
#include "Actor.h"

ColliderComponent::ColliderComponent(class Actor* actor)
    :Component(actor)
    , mRadius(0.0f)
{
}

// ���S���W���擾
const Vector2& ColliderComponent::GetCenter() const
{
    return mActor->GetPosition();
}

// �X�P�[�����l���������a��ԋp
float ColliderComponent::GetRadius() const
{
    return mActor->GetScale() * mRadius;
}

// �Փˏ���
bool Intersect(const ColliderComponent& a, const ColliderComponent& b)
{
    // �v�Z���׌y���̂���sqrt�����ɔ�r
    // �Փ˂������̂Ƃ̋���
    Vector2 diff = a.GetCenter() - b.GetCenter();
    float distSq = diff.LengthSq();
    // �Փˉ~�̔��a�̍��v�ȉ��Ȃ�Փ�
    float radDiff = a.GetRadius() + b.GetRadius();
    return distSq <= radDiff * radDiff;
}
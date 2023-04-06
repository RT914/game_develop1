#include "Component.h"
#include "Actor.h"

Component::Component(Actor* actor, int updateOrder)
    :mActor(actor)
    , mUpdateOrder(updateOrder)
{
    // �A�N�^�ɃR���|�[�l���g��ǉ�
    mActor->AddComponent(this);
}

Component::~Component()
{
    // �A�N�^����R���|�[�l���g���폜
    mActor->RemoveComponent(this);
}

void Component::Update(float deltaTime)
{
}
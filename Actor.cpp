#include "Actor.h"
#include <vector>
#include "Game.h"
#include "Component.h"
#include "SpriteComponent.h"

Actor::Actor(Game* game)
    :mState(EActive)
    , mPosition(Vector2::Zero)
    , mScale(1.0f)
    , mRotation(0.0f)
    , mGame(game)
{
    // �A�N�^�ǉ�
    mGame->AddActor(this);
}

Actor::~Actor()
{
    // �A�N�^�폜
    mGame->RemoveActor(this);
    // �R���|�[�l���g�폜
    while (!mComponents.empty())
    {
        delete mComponents.back();
    }
}

// �X�V����
void Actor::Update(float deltaTime)
{
    if (mState == EActive)
    {
        UpdateComponents(deltaTime);
        UpdateActor(deltaTime);
    }
}

// �R���|�[�l���g�X�V����
void Actor::UpdateComponents(float deltaTime)
{
    for (auto component : mComponents)
    {
        component->Update(deltaTime);
    }
}

// �A�N�^�X�V����
void Actor::UpdateActor(float deltaTime)
{
}

// �R���|�[�l���g�ǉ�
void Actor::AddComponent(Component* component)
{
    // �ݒ肳�ꂽ�X�V���ƂȂ�悤�\�[�g����
    int myOrder = component->GetUpdateOrder();
    auto iter = mComponents.begin();
    for (; iter != mComponents.end(); ++iter)
    {
        if (myOrder < (*iter)->GetUpdateOrder())
        {
            break;
        }
    }
    mComponents.insert(iter, component);
}

// �R���|�[�l���g�폜
void Actor::RemoveComponent(Component* component)
{
    auto iter = std::find(mComponents.begin(), mComponents.end(), component);
    if (iter != mComponents.end())
    {
        mComponents.erase(iter);
    }
}
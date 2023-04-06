#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <vector>
#include "Vector2.h"

// �A�N�^�N���X
// *�e�A�N�^�͂��̃N���X���p������
class Actor
{
public:
    enum State
    {
        EActive, // �A�N�e�B�u
        EDead    // ���S
    };

    Actor(class Game* game);
    virtual ~Actor();

    void Update(float deltaTime);              // �X�V����
    void UpdateComponents(float deltaTime);    // �R���|�[�l���g�X�V����
    virtual void UpdateActor(float deltaTime); // �A�N�^�X�V����

    void AddComponent(class Component* component);    // �R���|�[�l���g�ǉ�����
    void RemoveComponent(class Component* component); // �R���|�[�l���g�폜����

private:
    State mState;      // ���
    Vector2 mPosition; // �ʒu
    float mScale;      // �傫��
    float mRotation;   // ��]
    std::vector<class Component*> mComponents; // �ۗL����R���|�[�l���g
    class Game* mGame; // �Q�[���N���X

public:
    // Getter, Setter
    State GetState() const { return mState; }
    void SetState(const State state) { mState = state; }
    const Vector2& GetPosition() const { return mPosition; }
    void SetPosition(const Vector2& pos) { mPosition = pos; }
    float GetScale() const { return mScale; }
    void SetScale(const float scale) { mScale = scale; }
    float GetRotation() const { return mRotation; }
    void SetRotation(const float rotation) { mRotation = rotation; }
    class Game* GetGame() const { return mGame; }
};

#endif

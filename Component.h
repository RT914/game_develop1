#ifndef _COMPONENT_H_
#define _COMPONENT_H_


// �R���|�[�l���g�N���X
// *�e�R���|�[�l���g�͂��̃N���X���p������
class Component
{
public:
    Component(class Actor* owner, int updateOrder = 100);
    virtual ~Component();
    virtual void Update(float deltaTime); // �R���|�[�l���g�X�V����

protected:
    class Actor* mActor; // �R���|�[�l���g��ǉ�����A�N�^
    int mUpdateOrder;    // �R���|�[�l���g�X�V�̏���

public:
    // Getter, Setter
    int GetUpdateOrder() const { return mUpdateOrder; }
};
#endif

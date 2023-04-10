#ifndef _SCROLLSPRITECOMPONENT_H_
#define _SCROLLSPRITECOMPONENT_H_

#include "SpriteComponent.h"
#include "Vector2.h"

// �X�v���C�g�X�N���[���R���|�[�l���g
// *�ݒ肵�����x�ŃX�v���C�g���X�N���[������
class ScrollSpriteComponent : public SpriteComponent {
public:
    ScrollSpriteComponent(class Actor* actor, int drawOrder = 100);
    void Update(float deltaTime) override;
    void Draw(SDL_Renderer* renderer) override;

private:
    float mScrollSpeedX; // X�����̃X�N���[�����x
    float mOffsetX;      // X�����̃I�t�Z�b�g�l

    float mScrollSpeedY; // Y�����̃X�N���[�����x
    float mOffsetY;      // Y�����̃I�t�Z�b�g�l

public:
    // Setter, Getter
    void SetScrollSpeedX(float speed) { mScrollSpeedX = speed; }
    void SetScrollSpeedY(float speed) { mScrollSpeedY = speed; }

};

#endif

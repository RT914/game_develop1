#ifndef _SPRITECOMPONENT_H_
#define _SPRITECOMPONENT_H_

#include "SDL.h"
#include "Component.h"
#include "Player.h"

// �X�v���C�g�R���|�[�l���g�N���X
// *�`����s���R���|�[�l���g�͂��̃N���X���p������
class SpriteComponent : public Component
{
public:
    SpriteComponent(class Actor* actor, int drawOrder = 100);
    ~SpriteComponent();

    virtual void Draw(SDL_Renderer* renderer);     // �`�揈��
    virtual void SetTexture(SDL_Texture* texture); // �e�N�X�`���ݒ菈��

protected:
    SDL_Texture* mTexture;
    int mDrawOrder; // �`�揇
    int mTexWidth;  // �e�N�X�`������
    int mTexHeight; // �e�N�X�`���c��

public:
    // Getter, Setter
    int GetDrawOrder() const { return mDrawOrder; }
    int GetTexWidth() const { return mTexWidth; }
    int GetTexHeight() const { return mTexHeight; }
};

#endif

#include "ScrollSpriteComponent.h"
#include "Game.h"
#include "Actor.h"

ScrollSpriteComponent::ScrollSpriteComponent(class Actor* actor, int drawOrder)
    :SpriteComponent(actor, drawOrder)
    , mScrollSpeedY(0.0f)
    , mOffsetY(0.0f)
{
}

void ScrollSpriteComponent::Update(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    SpriteComponent::Update(deltaTime);
    // �I�t�Z�b�g�l���X�V
    mOffsetY += mScrollSpeedY * deltaTime;
    if (mOffsetY > Game::ScreenHeight)
    {
        mOffsetY -= Game::ScreenHeight;
    }
}

void ScrollSpriteComponent::Draw(SDL_Renderer* renderer)
{
    // �X�N���[�������邽�߂Q�����ׂĕ`�悷��
    // �ʏ�̃e�N�X�`���`��
    // �c����
    SDL_Rect r_bottom;
    r_bottom.w = static_cast<int>(mTexWidth * mActor->GetScale());
    r_bottom.h = static_cast<int>(mTexHeight * mActor->GetScale());
    r_bottom.x = static_cast<int>(mActor->GetPosition().x - r_bottom.w / 2);
    r_bottom.y = static_cast<int>(mActor->GetPosition().y - r_bottom.h / 2 + mOffsetY); // �I�t�Z�b�g��������
    SDL_RenderCopy(renderer,
        mTexture,
        nullptr,
        &r_bottom);

    // �ʏ�e�N�X�`���̏㕔�ɂ����ꖇ�`��
    SDL_Rect r_top;
    r_top.w = static_cast<int>(mTexWidth * mActor->GetScale());
    r_top.h = static_cast<int>(mTexHeight * mActor->GetScale());
    r_top.x = static_cast<int>(mActor->GetPosition().x - r_top.w / 2);
    r_top.y = static_cast<int>(mActor->GetPosition().y - r_top.h / 2 - Game::ScreenHeight + mOffsetY); // �X�N���[���T�C�Y������
    SDL_RenderCopy(renderer,
        mTexture,
        nullptr,
        &r_top);

    /*
    // ������
    SDL_Rect r_bottom;
    r_bottom.w = static_cast<int>(mTexWidth * mActor->GetScale());
    r_bottom.h = static_cast<int>(mTexHeight * mActor->GetScale());
    r_bottom.x = static_cast<int>(mActor->GetPosition().x - r_bottom.w / 2);
    r_bottom.y = static_cast<int>(mActor->GetPosition().y - r_bottom.h / 2 + mOffsetY); // �I�t�Z�b�g��������
    SDL_RenderCopy(renderer,
        mTexture,
        nullptr,
        &r_bottom);

    // �ʏ�e�N�X�`���̏㕔�ɂ����ꖇ�`��
    SDL_Rect r_top;
    r_top.w = static_cast<int>(mTexWidth * mActor->GetScale());
    r_top.h = static_cast<int>(mTexHeight * mActor->GetScale());
    r_top.x = static_cast<int>(mActor->GetPosition().x - r_top.w / 2);
    r_top.y = static_cast<int>(mActor->GetPosition().y - r_top.h / 2 - Game::ScreenHeight + mOffsetY); // �X�N���[���T�C�Y������
    SDL_RenderCopy(renderer,
        mTexture,
        nullptr,
        &r_top);
        */
}
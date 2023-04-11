#include "SpriteComponent.h"
#include "Game.h"
#include "Actor.h"
#include "Math.h"
#include <iostream>

SpriteComponent::SpriteComponent(class Actor* actor, int drawOrder)
    :Component(actor)
    , mTexture(nullptr)
    , mDrawOrder(drawOrder)
    , mTexWidth(0)
    , mTexHeight(0)
{
    // �`�撆�̃X�v���C�g�Ƃ��Ēǉ�
    mActor->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
    // �`�撆�̃X�v���C�g����폜
    mActor->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
    if (mTexture)
    {
        SDL_Rect r;
        // �傫���A�ʒu�i������W�j��ݒ�
        r.w = static_cast<int>(mTexWidth * mActor->GetScale());
        // std::cout << r.w << std::endl;
        r.h = static_cast<int>(mTexHeight * mActor->GetScale());
        r.x = static_cast<int>(mActor->GetPosition().x - r.w / 2);
        // std::cout << mActor->GetPosition().x << std::endl;
        r.y = static_cast<int>(mActor->GetPosition().y - r.h / 2);
        
        // �`��
        SDL_RenderCopyEx(renderer,
            mTexture,
            nullptr,
            &r,
            -Math::ToDegrees(mActor->GetRotation()),
            nullptr,
            SDL_FLIP_NONE);
            
    }
    else {

        // �`��F�𔒐F�ɐݒ�
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_Rect player{
            // �傫���A�ʒu�i������W�j��ݒ�
            static_cast<int>(mActor->GetPosition().x),
            static_cast<int>(mActor->GetPosition().y),
            static_cast<int>(30 * mActor->GetScale()), // player�̑傫��
            static_cast<int>(30 * mActor->GetScale())  // player�̑傫��
        };

        // �`��
        SDL_RenderFillRect(renderer, &player);

    }
    
}

// �e�N�X�`���ݒ菈��
void SpriteComponent::SetTexture(SDL_Texture* texture)
{
    mTexture = texture;
    // �e�N�X�`�����畝��ݒ�
    SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}
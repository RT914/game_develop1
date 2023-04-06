#include "SpriteComponent.h"
#include "Game.h"
#include "Actor.h"
#include "Math.h"

SpriteComponent::SpriteComponent(class Actor* actor, int drawOrder)
    :Component(actor)
    , mTexture(nullptr)
    , mDrawOrder(drawOrder)
    , mTexWidth(10)
    , mTexHeight(10)
{
    // 描画中のスプライトとして追加
    mActor->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
    // 描画中のスプライトから削除
    mActor->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
    if (mTexture)
    {
        SDL_Rect r;
        // 大きさ、位置（左上座標）を設定
        r.w = static_cast<int>(mTexWidth * mActor->GetScale());
        r.h = static_cast<int>(mTexHeight * mActor->GetScale());
        r.x = static_cast<int>(mActor->GetPosition().x - r.w / 2);
        r.y = static_cast<int>(mActor->GetPosition().y - r.h / 2);
        
        // 描画
        SDL_RenderCopyEx(renderer,
            mTexture,
            nullptr,
            &r,
            -Math::ToDegrees(mActor->GetRotation()),
            nullptr,
            SDL_FLIP_NONE);
            
    }
    else {

        // 描画色を白色に設定
        SDL_SetRenderDrawColor(renderer, 255, 100, 5, 255);

        SDL_Rect player{
            // 大きさ、位置（左上座標）を設定
            static_cast<int>(mActor->GetPosition().x),
            static_cast<int>(mActor->GetPosition().y),
            static_cast<int>(10 * mActor->GetScale()),
            static_cast<int>(10 * mActor->GetScale())
        };

        // 描画
        SDL_RenderFillRect(renderer, &player);

    }
    
}

// テクスチャ設定処理
void SpriteComponent::SetTexture(SDL_Texture* texture)
{
    mTexture = texture;
    // テクスチャから幅を設定
    SDL_QueryTexture(texture, nullptr, nullptr, &mTexWidth, &mTexHeight);
}
#include "ExplosionEffect.h"
#include "Game.h"
#include "SpriteComponent.h"

ExplosionEffect::ExplosionEffect(class Game* game, int num)
    :Actor(game)
    , mTimeCount(0.0f)
{
    // �X�v���C�g�ݒ�
    auto* sprite = new SpriteComponent(this);
    if (num == 1) { // �v���C���[
        sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "boom.png"));
    }
    else if (num == 2) { // �s�[�i�b�c�Ɗ`�̎�
        sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "kp_explosion.png"));
    }
    else {
        sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "kp_explosion.png"));
    }
    
    // �ŏ��͑傫��0�ɂ���
    SetScale(0.0f);
}

void ExplosionEffect::UpdateActor(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    Actor::UpdateActor(deltaTime);
    // ���X�ɑ傫������
    float changeScale = mTimeCount / DisplayTime * 3.0f;
    if (changeScale > 1.0f)
    {
        changeScale = 1.0f;
    }
    SetScale(changeScale);
    // �\�����Ԃ��߂�����j��
    mTimeCount += deltaTime;
    if (mTimeCount >= DisplayTime)
    {
        SetState(EDead);
    }
}
#include "Missile.h"
#include "Enemy.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "ColliderComponent.h"
#include "ExplosionEffect.h"

Missile::Missile(class Game* game)
    :Actor(game)
{
    // �X�v���C�g�ǉ�
    auto* sprite = new SpriteComponent(this, 90);
    sprite->SetTexture(GetGame()->LoadTexture(GetGame()->GetAssetsPath() + "kakinotane.png")); // �~�T�C���̉摜���Z�b�g
    // �R���C�_�ǉ�
    mCollider = new ColliderComponent(this);
    mCollider->SetRadius(50.0f * GetScale());
}

// �A�N�^�X�V
void Missile::UpdateActor(float deltaTime)
{
    // �e�̃��\�b�h�Ăяo��
    Actor::UpdateActor(deltaTime);
    // �~�T�C�����ړ�������
    Vector2 pos = GetPosition();
    pos.x += mMissileSpeed * deltaTime;
    
    // ��ʏ㕔�Ŕj��
    if (pos.y <= 50.0f)
    {
        SetState(EDead);
    }
    SetPosition(pos);

    
    // �G�l�~�[�Ƃ̏Փ˔���
    for (auto enemy : GetGame()->GetEnemies())
    {
        if (Intersect(*mCollider, *(enemy->GetCollider())))
        {
            SetState(EDead);
            enemy->SetState(EDead);
            // �G�l�~�[�̈ʒu�Ŕ���������
            // enemy->GetScale();
            auto* explosioneffect = new ExplosionEffect(GetGame());
            explosioneffect->SetPosition(Vector2(enemy->GetPosition()));
            break;
        }
    }
    
}
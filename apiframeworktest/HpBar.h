#pragma once
#include "Object.h"
class HpBar : public Object
{
private:
    float   m_hpBarIndex;

    Vec2    m_hpBarPos;
public:
    void SetHpIndex(float _hpBar);
    void SetHpBarPos(Vec2 _vPos);

public:
    virtual void Update() override; 
    virtual void Render(HDC _dc) override;
    CLONE(HpBar)

public:
    HpBar();
    ~HpBar();
};


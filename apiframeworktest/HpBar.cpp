#include "pch.h"
#include "HpBar.h"
#include "SelectGDI.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

HpBar::HpBar() : m_hpBarIndex(190), m_hpBarPos(Vec2(0.f, 0.f))
{

}

void HpBar::SetHpIndex(float _minusValue)
{
	m_hpBarIndex -= _minusValue;

	if (m_hpBarIndex <= 0) {
		ChangeScene(SCENE_TYPE::SCENE_01);
	}
}

void HpBar::SetHpBarPos(Vec2 _vPos)
{
	m_hpBarPos.x = _vPos.x - 90.f;
	m_hpBarPos.y -= _vPos.y - 20.f;

	SetPos(m_hpBarPos);
}

void HpBar::Render(HDC _dc)
{
	PEN_TYPE ePen = PEN_TYPE::RED;
//	SelectGDI p(_dc, ePen);
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(_dc, redBrush);
	
	Rectangle
	(_dc,
		m_hpBarPos.x, 
		m_hpBarPos.y - 25,
		m_hpBarPos.x + m_hpBarIndex, 
		m_hpBarPos.y);

	Component_Render(_dc);

	SelectObject(_dc, oldBrush);

	DeleteObject(redBrush);
}

void HpBar::Update()
{
}


HpBar::~HpBar()
{
}

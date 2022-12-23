#include "pch.h"
#include "Monster.h"
#include "ResMgr.h"
#include "TimeMgr.h"
#include "Image.h"
#include "Animator.h"
#include "Animation.h"
Monster::Monster()
	: m_fSpeed(100.f)
	, m_fMaxDistance(50.f)
	, m_vCenterPos(Vec2(0.f, 0.f))
	, m_iDir(1)
	, m_iHp(5)
{
	m_pImage = ResMgr::GetInst()->ImgLoad(L"EnemyPng", L"Image\\enemy.bmp");

	//CreateCollider();
	//GetCollider()->SetScale(Vec2(40.f, 40.f));

	/*CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwootest", m_pImage, Vec2(0.f, 100.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwootest", true);*/
}

Monster::~Monster()
{
}

void Monster::Update()
{
	//GetAnimator()->Update();
}

void Monster::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();

	//Component_Render(_dc);
	//¸¶Á¨Å¸ »ö»ó »¬¶§ transparent: Åõ¸íÇÑ

	Vec2 vPos = GetPos();
	TransparentBlt(_dc
			, (int)(vPos.x - (float)(Width / 2))
			, (int)(vPos.y - (float)(Height / 2))
			,Width, Height
		    , m_pImage->GetDC()
		    ,0,0, Width, Height
		    , RGB(255,0,255));
}


// 
//void Monster::EnterCollision(Collider* _pOther)
//{
//	Object* pOtherObj = _pOther->GetObj();
//	if (pOtherObj->GetName() == L"Bullet_Player")
//	{
//		m_iHp -= 1;
//		if(m_iHp <= 0)
//			DeleteObject(this);
//	}
//}


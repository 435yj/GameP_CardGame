#include "pch.h"
#include "Player.h"
#include "KeyMgr.h"
#include "TimeMgr.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"
Player::Player()
{
	// collider ����
	//CreateCollider();
	//etCollider()->SetScale(Vec2(20.f, 30.f));
	//m_pImage = ResMgr::GetInst()->ImgLoad(L"Player", L"Image\\plane.bmp");

	// image ���ε�
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");

	// animator ���� �� animation ���
	CreateAnimator();
	GetAnimator()->CreateAnimation(L"Jiwoofront", pImg, Vec2(0.f, 150.f), Vec2(50.f, 50.f), Vec2(50.f, 0.f), 5, 0.2f);
	GetAnimator()->Play(L"Jiwoofront", true);

	// animation offset ���� �ø���. 
	Animation* pAnim = GetAnimator()->FindAnimation(L"Jiwoofront");
	for(size_t i=0;i<pAnim->GetMaxFrame();i++)
		pAnim->GetFrame(i).vOffset = Vec2(10.f, -50.f);
}

Player::~Player()
{
	//if(nullptr !=m_pImage)
	//	delete m_pImage;
}
void Player::Update()
{
	GetAnimator()->Update();

	float playerPosX = WINHALFSIZEX - 500.f;
	float playerPosY = WINHALFSIZEY + 250.f;

	Vec2 playerSetPos = Vec2({ playerPosX, playerPosY });
	SetPos(playerSetPos);
}

void Player::Render(HDC _dc)
{
	Component_Render(_dc);
	//int Width = (int)m_pImage->GetWidth();
	//int Height = (int)m_pImage->GetHeight();

	//Vec2 vPos = GetPos();
	//BitBlt(_dc
	//	,(int)(vPos.x - (float)(Width / 2))
	//	,(int)(vPos.y - (float)(Height / 2))
	//    , Width, Height
	//    , m_pImage->GetDC()
	//    , 0,0, SRCCOPY);

	//����Ÿ ���� ���� transparent: ������
	//TransparentBlt(_dc
	//	, (int)(vPos.x - (float)(Width / 2))
	//	, (int)(vPos.y - (float)(Height / 2))
	//	,Width, Height
	//    , m_pImage->GetDC()
	//    ,0,0, Width, Height
	//    , RGB(255,0,255));

}

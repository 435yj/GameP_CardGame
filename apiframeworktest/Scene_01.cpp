#include "pch.h"
#include "Scene_01.h"
#include "KeyMgr.h"
#include "ResMgr.h"

Scene_01::Scene_01()
{
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	// image 업로드
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"PlayerAni", L"Image\\jiwoo.bmp");
}

void Scene_01::Exit()
{
}

void Scene_01::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
	// 만약 카드가 두짝 맞춰졌다.
	// if class::card 입장에서 카드가 두짝 맞춰졌는지 확인
	// 1) 몬스터한테 데미지를 준다.
	// 몬스터가 데미지를 받았다는 신호를 받으면
	// 몬스터는 몬스터 바에게 줄이라고 주는거야.
	// 몬스터가 죽으면 몬스터바도 같이 줄어들고.. 
	
	// 2) 몬스터한테 데미지를 줬어.
	// 몬스터바의 게이지를 줄여.
	// 몬스터의 게이지가 다 달았어. 몬스터바가 몬스터한테 
	// 다달았으니까 너 죽어라고 신호를 줘야겠지.

}

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
	// image ���ε�
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
	// ���� ī�尡 ��¦ ��������.
	// if class::card ���忡�� ī�尡 ��¦ ���������� Ȯ��
	// 1) �������� �������� �ش�.
	// ���Ͱ� �������� �޾Ҵٴ� ��ȣ�� ������
	// ���ʹ� ���� �ٿ��� ���̶�� �ִ°ž�.
	// ���Ͱ� ������ ���͹ٵ� ���� �پ���.. 
	
	// 2) �������� �������� ���.
	// ���͹��� �������� �ٿ�.
	// ������ �������� �� �޾Ҿ�. ���͹ٰ� �������� 
	// �ٴ޾����ϱ� �� �׾��� ��ȣ�� ��߰���.

}

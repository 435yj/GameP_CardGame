#include "pch.h"
#include "Scene_02.h"
#include "KeyMgr.h"
Scene_02::Scene_02()
{
}

Scene_02::~Scene_02()
{
}

void Scene_02::Enter()
{
}

void Scene_02::Exit()
{
}

void Scene_02::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::ENTER))
	{
		ChangeScene(SCENE_TYPE::START);
	}
}

#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "HpBar.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
Scene_Start::Scene_Start()
{
}

Scene_Start::~Scene_Start()
{
}
void Scene_Start::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
	SoundMgr::GetInst()->Play(L"BGM");
	// Object 추가
	
	float playerPosX = WINHALFSIZEX - 500.f;
	float playerPosY = WINHALFSIZEY + 200.f;

	Vec2 playerSetPos = Vec2({ playerPosX, playerPosY });
	Object* pObj = new Player;

	pObj->SetPos(playerSetPos);
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	m_pHpBar = new HpBar;
	m_pHpBar->SetHpBarPos(Vec2({ WINHALFSIZEX - 500.f, -500.f }));

	AddObject(m_pHpBar, GROUP_TYPE::HPBAR);

	//	Object* pOtherPlayer = new Player(*(Player*)pObj);
		/*Object* pOtherPlayer = pObj->Clone();
		pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
		AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/

		//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 

		// Monster Object 추가
		//Monster* pMonsterObj = new Monster;
		//pMonsterObj->SetPos(Vec2(640.f, 50.f));
		//pMonsterObj->SetScale(Vec2(50.f, 50.f));
		//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
		//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);

		// 몬스터 배치
	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
	int iMonster = 16;
	float fMoveDist = 25.f;
	float fObjScale = 50.f;
	float fTerm = (vResolution.x - ((fMoveDist + fObjScale / 2.f) * 2)) / (float)(iMonster - 1);
	Monster* pMonsterObj = nullptr;
	
	pMonsterObj = new Monster;
	pMonsterObj->SetName(L"Monster");
	pMonsterObj->SetPos(Vec2({ WINHALFSIZEX - 500.f, 170.f }));
	pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
	pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
	
	AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
	
	HpBar* monsterHpBar = nullptr;
	monsterHpBar = new HpBar;
	monsterHpBar->SetHpBarPos(Vec2({ WINHALFSIZEX - 500.f, -60.f }));

	AddObject(monsterHpBar, GROUP_TYPE::HPBAR);
	
	//pObj = new Object;

	//pObj->SetPos(Vec2(640.f, 384.f));
	//pObj->SetScale(Vec2(100.f, 100.f));

	//AddObject(pObj, GROUP_TYPE::DEFAULT);
	// 충돌 지정 
	// Player - Monster 그룹 간의 충돌 체크
	/*CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);*/

}

void Scene_Start::Exit()
{
	DeleteAll();
	//CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{
	Scene::Update();

	if (KEY_TAP(KEY::V))
	{
		m_pHpBar->SetHpIndex(45);
	}

}

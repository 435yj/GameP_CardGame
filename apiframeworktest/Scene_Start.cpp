#define ID_ROCK 1
#define ID_SISSORS 2
#define ID_PAPER 3
#include "pch.h"
#include "Scene_Start.h"
#include "Object.h"
#include "Player.h"
#include "Monster.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
Scene_Start::Scene_Start()
{

}

Scene_Start::~Scene_Start()
{
}

int game(char you, char computer)
{
    if (you == computer)
        return (int)-1;

    if (you == 's' && computer == 'p')
        return (int)0;

    else if (you == 'p' && computer == 's') return (int)1;

    if (you == 's' && computer == 'z')
        return (int)1;

    else if (you == 'z' && computer == 's')
        return (int)0;

    if (you == 'p' && computer == 'z')
        return (int)0;

    else if (you == 'z' && computer == 'p')
        return (int)1;
    return (int)-1;
}

void Scene_Start::Enter()
{


//	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\pianobgm.wav");
//	SoundMgr::GetInst()->Play(L"BGM");
//	// Object 추가
//	Object* pObj = new Player;
//	pObj->SetPos(Vec2(Core::GetInst()->GetResolution().x/2, Core::GetInst()->GetResolution().y/2));
//	pObj->SetScale(Vec2(100.f,100.f));
//	AddObject(pObj, GROUP_TYPE::PLAYER);
//
////	Object* pOtherPlayer = new Player(*(Player*)pObj);
//	/*Object* pOtherPlayer = pObj->Clone();
//	pOtherPlayer->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + 100.f, Core::GetInst()->GetResolution().y / 2.f));
//	AddObject(pOtherPlayer, GROUP_TYPE::PLAYER);*/
//
//	//m_vecObj[(UINT)GROUP_TYPE::DEFAULT].push_back(pObj); 
//	// Monster Object 추가
//	//Monster* pMonsterObj = new Monster;
//	//pMonsterObj->SetPos(Vec2(640.f, 50.f));
//	//pMonsterObj->SetScale(Vec2(50.f, 50.f));
//	//pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
//	//AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
//
//	// 몬스터 배치
//	Vec2 vResolution(Vec2(Core::GetInst()->GetResolution()));
//	int iMonster = 16;
//	float fMoveDist = 25.f;
//	float fObjScale = 50.f;
//	float fTerm = (vResolution.x - ((fMoveDist + fObjScale /2.f) * 2)) / (float)(iMonster-1);
//	Monster* pMonsterObj = nullptr;
//	for (int i = 0; i < iMonster; i++)
//	{
//		pMonsterObj = new Monster;
//		pMonsterObj->SetName(L"Monster");
//		pMonsterObj->SetPos(Vec2((fMoveDist + fObjScale / 2.f) + (float)i*fTerm, 50.f));
//		pMonsterObj->SetScale(Vec2(fObjScale, fObjScale));
//		pMonsterObj->SetCenterPos(pMonsterObj->GetPos());
//		pMonsterObj->SetMoveDistance(fMoveDist);
//		AddObject(pMonsterObj, GROUP_TYPE::MONSTER);
//	}
//	//pObj = new Object;
//
//	//pObj->SetPos(Vec2(640.f, 384.f));
//	//pObj->SetScale(Vec2(100.f, 100.f));
//
//	//AddObject(pObj, GROUP_TYPE::DEFAULT);
//	// 충돌 지정 
//	// Player - Monster 그룹 간의 충돌 체크
//	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::PLAYER, GROUP_TYPE::MONSTER);
//	CollisionMgr::GetInst()->CheckGroup(GROUP_TYPE::BULLET_PLAYER, GROUP_TYPE::MONSTER);

}

void Scene_Start:: HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void Scene_Start::ShowConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

bool Scene_Start:: IsConsoleVisible()
{
    return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}

const wchar_t* result_win = L"You Win!\n";
const wchar_t* result_loose = L"You Loose!\n";
const wchar_t* result_draw = L"It's a draw!\n";
HINSTANCE g_hinst = GetModuleHandle(0);
HBITMAP hBitmap;

int n, i, result;
char you, computer;

HWND radiogroup;
HWND radiobutton_handle_1;
HWND radiobutton_handle_2;
HWND radiobutton_handle_3;

HDC hdc, MemDc;
PAINTSTRUCT ps;
HBITMAP MyBitmap, OldBitmap;


BITMAP bitmap;
BITMAP bitmap2;
HGDIOBJ oldBitmap;
HGDIOBJ oldBitmap2;



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {

    HWND hwnd;

    MSG  msg;
    WNDCLASSW wc = { 0 };
    wc.lpszClassName = L"Rock-Sissors-Paper";
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);

    g_hinst = hInstance;

    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, L"Rock-Sissors-Paper",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE | SS_BITMAP,
        100, 100, 500, 220, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) 
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) 
{





    

    switch (msg) {

    case WM_CREATE:

        InitCommonControls();

        radiogroup = CreateWindowExW(0, L"Button", L"Choose:",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
            10, 10, 120, 110, hwnd, NULL, g_hinst, NULL);

        radiobutton_handle_1 = CreateWindowExW(0, L"Button", L"Rock",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP | WS_TABSTOP,
            20, 30, 100, 30, hwnd, (HMENU)ID_ROCK, g_hinst, NULL);
        radiobutton_handle_2 = CreateWindowExW(0, L"Button", L"Sissors",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            20, 55, 100, 30, hwnd, (HMENU)ID_SISSORS, g_hinst, NULL);
        radiobutton_handle_3 = CreateWindowExW(0, L"Button", L"Paper",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            20, 80, 100, 30, hwnd, (HMENU)ID_PAPER, g_hinst, NULL);
        break;

    case WM_COMMAND:

        if (MyBitmap != NULL) {
            EnableWindow(radiogroup, FALSE);
            EnableWindow(radiobutton_handle_1, FALSE);
            EnableWindow(radiobutton_handle_2, FALSE);
            EnableWindow(radiobutton_handle_3, FALSE);
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }

        if (HIWORD(wParam) == BN_CLICKED) {
            switch (LOWORD(wParam)) {

            case ID_ROCK:
                you = 's';
                MemDc = CreateCompatibleDC(hdc);
                MyBitmap = LoadBitmap(g_hinst, MAKEINTRESOURCE("IDB_BITMAP1"));
                OldBitmap = (HBITMAP)SelectObject(MemDc, MyBitmap);
                BitBlt(hdc, 0, 0, 123, 160, MemDc, 0, 0, SRCCOPY);
                //hBitmap = (HBITMAP)LoadImageW(NULL, L".\\Resource\\Left_Rock.bmp",
                //    IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);

                if (MyBitmap == NULL) {
                    MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
                }
                break;
            case ID_SISSORS:
                you = 'z';
                MemDc = CreateCompatibleDC(hdc);
                MyBitmap = LoadBitmap(g_hinst, MAKEINTRESOURCE("IDB_BITMAP2"));
                OldBitmap = (HBITMAP)SelectObject(MemDc, MyBitmap);
                BitBlt(hdc, 0, 0, 123, 160, MemDc, 0, 0, SRCCOPY);
                //MyBitmap = (HBITMAP)LoadImageW(NULL, L".\\pics\\Left_Sissors.bmp",
                //    IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);

                if (MyBitmap == NULL) {
                    MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
                }
                break;
            case ID_PAPER:
                you = 'p';
                MemDc = CreateCompatibleDC(hdc);
                MyBitmap = LoadBitmap(g_hinst, MAKEINTRESOURCE("IDB_BITMAP3"));
                OldBitmap = (HBITMAP)SelectObject(MemDc, MyBitmap);
                BitBlt(hdc, 0, 0, 123, 160, MemDc, 0, 0, SRCCOPY);
                //MyBitmap = (HBITMAP)LoadImageW(NULL, L".\\pics\\Left_Paper.bmp",
                //    IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);

                if (MyBitmap == NULL) {
                    MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
                }
                break;
            }
            InvalidateRect(hwnd, NULL, TRUE);
        }

        if (MyBitmap != NULL && OldBitmap == NULL) {

            srand(time(NULL));
            n = rand() % 100;
            if (n < 33) {

                computer = 's';
                MemDc = CreateCompatibleDC(hdc);
                MyBitmap = LoadBitmap(g_hinst, MAKEINTRESOURCE("IDB_BITMAP4"));
                OldBitmap = (HBITMAP)SelectObject(MemDc, MyBitmap);
                BitBlt(hdc, 0, 0, 123, 160, MemDc, 0, 0, SRCCOPY);
                //OldBitmap = (HBITMAP)LoadImageW(NULL, L".\\pics\\Right_Rock.bmp",
                //    IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            }
            else if (n > 33 && n < 66) {


                computer = 'p';
                MemDc = CreateCompatibleDC(hdc);
                MyBitmap = LoadBitmap(g_hinst, MAKEINTRESOURCE("IDB_BITMAP5"));
                OldBitmap = (HBITMAP)SelectObject(MemDc, MyBitmap);
                BitBlt(hdc, 0, 0, 123, 160, MemDc, 0, 0, SRCCOPY);
                //OldBitmap = (HBITMAP)LoadImageW(NULL, L".\\pics\\Right_Paper.bmp",
                //    IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            }
            else {

                computer = 'z';
                MemDc = CreateCompatibleDC(hdc);
                MyBitmap = LoadBitmap(g_hinst, MAKEINTRESOURCE("IDB_BITMAP6"));
                OldBitmap = (HBITMAP)SelectObject(MemDc, MyBitmap);
                BitBlt(hdc, 0, 0, 123, 160, MemDc, 0, 0, SRCCOPY);
                //OldBitmap = (HBITMAP)LoadImageW(NULL, L".\\pics\\Right_Sissors.bmp",
                //    IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            }

            if (OldBitmap == NULL) {
                MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
            }

            if (OldBitmap != NULL) {

                result = game(you, computer);

                switch (result) {
                case 0: // you loose
                    MessageBoxW(NULL, (LPCWSTR)result_loose, L"Result", MB_OK);
                    break;
                case 1: // you win
                    MessageBoxW(NULL, (LPCWSTR)result_win, L"Result", MB_OK);
                    break;
                case -1: // draw
                    MessageBoxW(NULL, (LPCWSTR)result_draw, L"Result", MB_OK);
                    break;
                }
            }
        }
        break;

    case WM_PAINT:

        if (MyBitmap == NULL || OldBitmap == NULL) {
            break;
        }


        hdc = BeginPaint(hwnd, &ps);
        MemDc = CreateCompatibleDC(hdc);

        oldBitmap = SelectObject(MemDc, MyBitmap);
        GetObject(MyBitmap, sizeof(bitmap), &bitmap);
        BitBlt(hdc, 160, 20, bitmap.bmWidth, bitmap.bmHeight,
            MemDc, 0, 0, SRCCOPY);
        SelectObject(MemDc, oldBitmap);

        oldBitmap2 = SelectObject(MemDc, OldBitmap);
        GetObject(OldBitmap, sizeof(bitmap2), &bitmap2);
        BitBlt(hdc, 320, 20, bitmap2.bmWidth, bitmap2.bmHeight, MemDc
            , 0, 0, SRCCOPY);
        SelectObject(MemDc, oldBitmap2);

        DeleteDC(MemDc);
        EndPaint(hwnd, &ps);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void Scene_Start::Exit()
{
	DeleteAll();
	CollisionMgr::GetInst()->CheckReset();
}

void Scene_Start::Update()
{
    Scene::Update();
    if (KEY_TAP(KEY::ENTER))
    {
        ChangeScene(SCENE_TYPE::SCENE_02);
        Rectangle(hdc, 100, 100, 200, 200);
    }
}


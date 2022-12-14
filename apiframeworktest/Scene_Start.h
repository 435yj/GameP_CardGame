#pragma once
#include "Scene.h"

class Scene_Start :
    public Scene
{
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
public:
    Scene_Start();
    virtual ~Scene_Start();
    void HideConsole();
    void ShowConsole();
    bool IsConsoleVisible();

public :
    LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};


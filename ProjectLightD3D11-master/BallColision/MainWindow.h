#pragma once
#pragma comment(lib,"d2d1")
#include <d2d1.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <ProjectRex.h>
#include "Keyboard.h"
#include "Mouse.h"
class MainWindow
{
	static HWND hWnd;
	static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
	WNDCLASS Class;
	HINSTANCE hInst;
	void ProcessInput(MSG msg);
public: MainWindow(HINSTANCE);
	   ~MainWindow();
	   bool ProcessMessage();
	    HWND GetHandle()const { return hWnd; }
public:Keyboard kbd;
	   Mouse mouse;
};

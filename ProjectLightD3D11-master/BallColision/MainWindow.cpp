#include "MainWindow.h"
#include "Keyboard.cpp"
#include "Mouse.cpp"
HWND MainWindow::hWnd = nullptr;


MainWindow::MainWindow(HINSTANCE hInst) :Class({ 0 })
{
    Class.hInstance = GetModuleHandle(nullptr);
	Class.lpfnWndProc = this->WindowProc;
	Class.lpszClassName = L"Project Rex";
	Class.hCursor = LoadCursor(NULL, IDC_ARROW);
	Class.hbrBackground = (HBRUSH)COLOR_WINDOW;
	Class.style = CS_HREDRAW | CS_VREDRAW|CS_DBLCLKS;
	this->hInst = hInst;
	RegisterClass(&Class);
	hWnd = CreateWindow(Class.lpszClassName, L"BallColission", 
		                 WS_VISIBLE | WS_OVERLAPPEDWINDOW, 
		                 CW_USEDEFAULT, CW_USEDEFAULT, 
		                1920, 1080, NULL, NULL, this->hInst, NULL);
	ShowWindow(hWnd, SW_MAXIMIZE);
}
MainWindow::~MainWindow()
{
	UnregisterClass(Class.lpszClassName, hInst);
}
bool MainWindow::ProcessMessage()
{
	MSG msg;
	while (PeekMessage(&msg, nullptr, NULL, NULL, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		ProcessInput(msg);
		if (msg.message == WM_QUIT)return false;
	}
	return true;
}
LRESULT CALLBACK MainWindow::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT Result = 0;
	switch (msg)
	{
	case WM_CLOSE:
	case WM_DESTROY:PostQuitMessage(0);break;
	default:Result = DefWindowProc(hWnd, msg, wParam, lParam);break;
	}
	return Result;
}
void MainWindow::ProcessInput(MSG msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN: {kbd.OnKeyPressed(GET_KEYSTATE_WPARAM(msg.wParam));
		if (msg.wParam == '+') { kbd.OnPlusPressed();}
		if (msg.wParam == '-') { kbd.OnMinusPressed();}
	                  }break;
	case WM_KEYUP: {kbd.OnKeyReleased(GET_KEYSTATE_WPARAM(msg.wParam));
		if (msg.wParam == '+') { kbd.OnPlusReleased(); }
		if (msg.wParam =='-'){kbd.OnMinusReleased();}
	                }break;
	case WM_LBUTTONDOWN: {mouse.MouseClickHasHappened(),mouse.SetPosition(LOWORD(msg.lParam), HIWORD(msg.lParam)), mouse.OnLMbuttonPress();}break;
	case WM_RBUTTONDOWN: {mouse.MouseClickHasHappened();mouse.SetPosition(LOWORD(msg.lParam), HIWORD(msg.lParam)), mouse.OnRMbuttonPress();}break;
	case WM_LBUTTONUP: {mouse.MouseClickHasEnded();mouse.OnLMbuttonRelease();mouse.OnLMbuttonDbclickEnd();}break;
	case WM_RBUTTONUP: {mouse.MouseClickHasEnded();mouse.OnRMbuttonRelease();}break;
	case WM_MOUSEMOVE: {mouse.SetPosition(LOWORD(msg.lParam), HIWORD(msg.lParam));}break;
	case WM_LBUTTONDBLCLK: {mouse.OnLMbuttonDbClick();mouse.SetPosition(LOWORD(msg.lParam), HIWORD(msg.lParam));}break;
	case WM_MOUSEWHEEL: {mouse.SetMouseDelta(GET_WHEEL_DELTA_WPARAM(msg.wParam));}
	}
	
}
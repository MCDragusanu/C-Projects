#include "MainWindow.cpp"
#include "Graphics.cpp"
#include "GamePublicMethods.cpp"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow)
{
	MainWindow wnd(hInst);
	HWND hWnd = wnd.GetHandle();
	Graphics gfx(hWnd);
	Game theGame(wnd, gfx);
	
	if (theGame.LoadRecources())
	{
		while (wnd.ProcessMessage())
		{
			theGame.Go();
		}
	}
}
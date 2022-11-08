#include "PreCompiledHeaders.h"
#include "Window.cpp"
#include "Graphics.cpp"
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow)
{
	/*Window Window(1920, 1080, std::string("ProjectLight"));
	Graphics Gfx(Window.GetHandle());

	while (Window.ProcessMessage())
	{
		Gfx.ClearBuffer(1.0f, 1.0f, 1.0f);
		Gfx.DrawCall();
		Gfx.EndFrame();
	}*/
	try
	{
		Window Window(1920, 1080, std::string("ProjectLight"));

	}
	catch (const __Exception& E)
	{
		MessageBox(nullptr, E.what(), E.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
}
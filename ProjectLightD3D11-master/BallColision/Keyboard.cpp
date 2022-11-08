#include "Keyboard.h"
#include <Windows.h>

void Keyboard::OnKeyPressed(unsigned flag)
{
	switch (flag)
	{
	case VK_UP:Key.ArrowUp = true;break;
	case VK_DOWN:Key.ArrowDown = true;break;
	case VK_RIGHT:Key.ArrowRight = true;break;
	case VK_LEFT:Key.ArrowLeft = true;break;
	}
}
void Keyboard::OnKeyReleased(unsigned flag)
{
	switch (flag)
	{
	case VK_UP:Key.ArrowUp =false;break;
	case VK_DOWN:Key.ArrowDown = false;break;
	case VK_RIGHT:Key.ArrowRight = false;break;
	case VK_LEFT:Key.ArrowLeft = false;break;
	}
}

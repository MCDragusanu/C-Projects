#include "Mouse.h"


void Mouse::OnLMbuttonPress()
{
	click.LMbutton = true;
	
}
void Mouse::OnLMbuttonRelease()
{
	click.LMbutton = false;
	
}
void Mouse::OnRMbuttonPress()
{
	click.RMbutton = true;
	
}
void Mouse::OnRMbuttonRelease()
{
	click.RMbutton = false;
	
}
void Mouse::SetPosition(unsigned short x, unsigned short y)
{
	MousePosition.x = x;
	MousePosition.y = y;
}
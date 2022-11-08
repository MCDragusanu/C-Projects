#include "Keyboard_and_Mouse.h"
bool Mouse::GetState(const int& event)
{
switch (event)
	{
	case (int)MouseState::LMButtonClick:return Event.LMButtonClick; break;
	case (int)MouseState::LMButtonRelease:return Event.LMButtonRelease; break;
	case(int)MouseState::RMButtonClick:return Event.RMButtonClick; break;
	case(int)MouseState::RMButtonRelease:return Event.RMButtonRelease; break;
	case(int)MouseState::MouseInside:return Event.MouseInside; break;
	case(int)MouseState::MouseOutside:return Event.MouseOutside; break;
	case(int)MouseState::LMbuttonDoubbleClick:return Event.LMbuttonDoubleClick; break;
	case(int)MouseState::RMButtonDoubleClick:return Event.RMButtonDoubleClick; break;
	case(int)MouseState::MWHeelUp:return Event.MWHeelUp; break;
	case(int)MouseState::MWheelDown:return Event.MWheelDown; break;
	default:return false;
	}
}

void Mouse::SetPosition(const int& x, const int& y)
{
	Position.x = (float)x;
	Position.y = (float)y;
}

bool Mouse::GetEvent(MouseState&& Enum)
{

	return GetState((int)Enum);
}

void Mouse::LMButtonIsPressed(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.LMButtonClick = true;
	Event.LMButtonRelease = false;
}

void Mouse::LMButtonIsReleased(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.LMButtonClick = false;
	Event.LMButtonRelease = true;
}

void Mouse::RMButtonIsPressed(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.RMButtonClick = true;
	Event.RMButtonRelease = false;
}

void Mouse::RMButtonIsReleased(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.RMButtonClick = false;
	Event.RMButtonRelease = true;
}

void Mouse::MouseMove(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.MouseInside = true;
	Event.MouseOutside = false;

}

void Mouse::MWheelMove(float&& Delta, const int& x, const int& y)
{
	SetPosition(x, y);
	if (Delta > 0)
	{

		Event.MWHeelUp = true;
		Event.MWheelDown = false;
	}
	if (Delta < 0) {
		Event.MWHeelUp = false;
		Event.MWheelDown = true;
	}
}

void Mouse::RMButtonDBClick(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.RMButtonDoubleClick = true;
}

void Mouse::LMButtonDBclick(const int& x, const int& y)
{
	SetPosition(x, y);
	Event.LMbuttonDoubleClick = true;
}

bool Keyboard::GetState(int&& event)
{
	switch (event)
	{
	case (int)SysKey::Delete:return Key.Delete; break;
	case (int)SysKey::Down:return Key.Down; break;
	case (int)SysKey::End:return Key.End; break;
	case (int)SysKey::Home:return Key.Home; break;
	case (int)SysKey::Left:return Key.Left; break;
	case (int)SysKey::Page_Down:return Key.Page_Down; break;
	case (int)SysKey::Page_Up:return Key.Page_Up; break;
	case (int)SysKey::Right:return Key.Right; break;
	case (int)SysKey::Shift:return Key.Shift; break;
	case (int)SysKey::Space:return Key.Space; break;
	case (int)SysKey::Up:return Key.Up; break;
	case (int)SysKey::Control:return Key.Control; break;
	case (int)SysKey::Enter:return Key.Enter; break;
	case (int)SysKey::Tab:return Key.Tab; break;
	case (int)SysKey::Alt:return Key.Alt; break;

	default:return Key.Unknown; break;
	}
}

bool Keyboard::GetSysKey(SysKey&& flag)
{
	return GetState((int)flag);
}
char Keyboard::GetKey()const
{
	return last_Key;
}
void Keyboard::SysKeyDown(const unsigned int& flag)
{
	switch (flag)
	{
	case VK_TAB:Key.Tab = true; break;
	case VK_RETURN:Key.Enter = true; break;
	case VK_SHIFT:Key.Shift = true; break;
	case VK_CONTROL:Key.Control = true; break;
	case VK_MENU:Key.Alt = true; break;
	case VK_SPACE:Key.Space = true; break;
	case VK_PRIOR:Key.Page_Up = true; break;
	case VK_NEXT:Key.Page_Down = true; break;
	case VK_END:Key.End = true; break;
	case VK_HOME:Key.Home = true; break;
	case VK_UP:Key.Up = true; break;
	case VK_DOWN:Key.Down = true; break;
	case VK_RIGHT:Key.Right = true; break;
	case VK_LEFT:Key.Left = true; break;
	case VK_BACK:Key.Delete = true; break;
	
	}
}
void Keyboard::SysKeyUp(const unsigned int& flag)
{
	switch (flag)
	{
	case VK_TAB:Key.Tab = false; break;
	case VK_RETURN:Key.Enter = false; break;
	case VK_SHIFT:Key.Shift = false; break;
	case VK_CONTROL:Key.Control = false; break;
	case VK_MENU:Key.Alt = false; break;
	case VK_SPACE:Key.Space = false; break;
	case VK_PRIOR:Key.Page_Up = false; break;
	case VK_NEXT:Key.Page_Down = false; break;
	case VK_END:Key.End = false; break;
	case VK_HOME:Key.Home = false; break;
	case VK_UP:Key.Up = false; break;
	case VK_DOWN:Key.Down = false; break;
	case VK_RIGHT:Key.Right = false; break;
	case VK_LEFT:Key.Left = false; break;
	case VK_BACK:Key.Delete = false; break;
	}
}

#pragma once
enum class SysKey :unsigned char
{
	Delete = 1,
	Shift,
	Space,
	Page_Up,
	Page_Down,
	End,
	Home,
	Left,
	Right,
	Up,
	Down,
	Enter,
	Tab,
	Control,
	Alt,
	Unknown,
	Keydown,
	KeyUp
};
class Keyboard
{

	char last_Key = ' ';
	struct Keystate
	{
		bool Delete = false,
			Shift = false,
			Space = false,
			Page_Up = false,
			Page_Down = false,
			End = false,
			Home = false,
			Left = false,
			Right = false,
			Up = false,
			Down = false,
			Enter = false,
			Tab = false,
			Control = false,
			Alt = false,
			Unknown = true;
	};

	Keystate Key;
	bool GetState(int&&);
public:
	  char GetKey()const;
	  void AutoRepeatEnable() { auto_repeat = true; }
	  void AutoRepeatDisable() { auto_repeat = false; }
	  bool auto_repeat = true;
	  void SetKey(const char& Key) {
		  last_Key = Key;

	  }
	  bool GetSysKey(SysKey&&);
	  void SysKeyDown(const unsigned int&);
	  void SysKeyUp(const unsigned int&);
	  bool keydown = true, keyup = true, space = false, Delete = false;

};
struct Point
{
	float x, y;
	Point(const float& valueX = 0, const float& valueY = 0) :x(valueX), y(valueY) {}
};
enum class MouseState :unsigned char
{
	LMButtonClick = 1,
	LMButtonRelease,
	RMButtonClick,
	RMButtonRelease,
	MouseInside,
	MouseOutside,
	LMbuttonDoubbleClick,
	RMButtonDoubleClick,
	MWHeelUp,
	MWheelDown
};
class Mouse
{
	Point Position;

	struct MouseEvent
	{
		bool LMButtonClick = false,
			LMButtonRelease = false,
			RMButtonClick = false,
			RMButtonRelease = false,
			MouseInside = false,
			MouseOutside = false,
			LMbuttonDoubleClick = false,
			RMButtonDoubleClick = false,
			MWHeelUp = false,
			MWheelDown = false;

	};
	bool GetState(const int& event);
	MouseEvent Event;
public:Mouse() {};
	  void SetPosition(const int&, const int&);
	  Point GetPosition()const { return Position; }
	  bool GetEvent(MouseState&&);
	  void LMButtonIsPressed(const int&, const int&);
	  void LMButtonIsReleased(const int&, const int&);
	  void RMButtonIsPressed(const int& x, const int& y);
	  void RMButtonIsReleased(const int& x, const int& y);
	  void MouseMove(const int& x, const int& y);
	  void MouseLeave(const int& x, const int& y) { SetPosition(x, y); Event.MouseOutside = true; Event.MouseInside = false; }
	  void MWheelMove(float&& Delta, const int& x, const int& y);
	  void RMButtonDBClick(const int&, const int&);
	  void LMButtonDBclick(const int&, const int&);
	  void DBClickEnd() { Event.LMbuttonDoubleClick = false; Event.RMButtonDoubleClick = false; }

};


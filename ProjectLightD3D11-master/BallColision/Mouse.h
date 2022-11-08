#pragma once


class Mouse
{
	D2D1_POINT_2F MousePosition;
	struct MouseButtons
	{
		bool LMbutton, RMbutton, DbClick,click;
		double delta=0;
	}click;
public:void SetPosition(unsigned short, unsigned short);
	  D2D1_POINT_2F GetMousePosition() { return MousePosition;}
	  void OnLMbuttonPress();
	  void OnLMbuttonRelease();
	  void OnRMbuttonPress();
	  void OnRMbuttonRelease();
	  MouseButtons GetMouseState() { return click; }
	  void OnLMbuttonDbClick() { click.DbClick = true; }
	  void OnLMbuttonDbclickEnd() { click.DbClick = false; }
	  void MouseClickHasHappened() { click.click = true;}
	  void MouseClickHasEnded() { click.click = false; }
	  void SetMouseDelta(float delta) { this->click.delta = delta; }
	  double GetMouseDelta() { return click.delta; }
};	  

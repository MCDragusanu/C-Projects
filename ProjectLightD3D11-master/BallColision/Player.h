#pragma once




class Player
{
	D2D1_ELLIPSE Shape;
	int id;
	int mass;
	unsigned int color;
	void clamp();
	struct VectorInfo
	{
		float Vx, Vy;
	}vectorinfo;
public:Player(float x = 0, float y = 0,unsigned int color = 0, int id = 0);
	  void ChangeColor(unsigned x = 0);
	  void DrawPlayer(Graphics& gfx);
	  void MovePlayer(Mouse mouse);
	  D2D1_ELLIPSE GetShape() { return Shape; }
	  void SetPosition(D2D1_POINT_2F Point) { Shape.point = Point; }
	  void SetPosition(float x, float y) { this->Shape.point = { x,y }; }
	  void MovePlayer(Keyboard kbd);
	  VectorInfo GetInfo() { return vectorinfo; }
	  void SetInfo(float x, float y) { vectorinfo.Vx = x;vectorinfo.Vy = y; }
	  void InvertX(){ vectorinfo.Vx = -vectorinfo.Vx;}
	  void InvertY(){ vectorinfo.Vy = -vectorinfo.Vy;}
	  int GetId() { return id; }
	  int GetMass() { return mass; }
};
#include "Player.h"
#include "Graphics.h"
#include "Mouse.h"
Player::Player(float x, float y,unsigned color, int id)
{
	Shape.point.x = x;
	Shape.point.y = y;
	vectorinfo = { rand() % 10*1.0f,rand() % 10*1.0f };
	this->color = color;
	this->id = id;
	this->mass = rand() % 10 + 3;
	Shape.radiusX = mass*15;
	Shape.radiusY = mass*15;
}
void Player::clamp()
{
	if (Shape.point.x+Shape.radiusX > 1920)
	{
		Shape.point.x = 1920 - Shape.radiusX;
		InvertX();
	}
	if (Shape.point.x- Shape.radiusX < 0)
	{
		Shape.point.x = Shape.radiusX;
		InvertX();
	}
	if (Shape.point.y+ Shape.radiusX > 1080)
	{
		Shape.point.y = 1080 - Shape.radiusX;
		InvertY();
	}
	if (Shape.point.y- Shape.radiusX < 0)
	{
		Shape.point.y = Shape.radiusX;
		InvertY();
	}
}
void Player::ChangeColor(unsigned  x)
{
	if (x)
	{
		this->color = x;
	}
	else this->color = color+=10;
}

void Player::DrawPlayer(Graphics& gfx)
{
	
	//clamp();
	gfx.DrawEllipse(Shape, color);
}
void Player::MovePlayer(Mouse mouse)
{
		this->Shape.point = mouse.GetMousePosition();		
}
void Player::MovePlayer(Keyboard kbd)
{
	Shape.point.x = Shape.point.x + vectorinfo.Vx;
	Shape.point.y = Shape.point.y + vectorinfo.Vy;
}
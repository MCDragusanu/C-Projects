#include "Game.h"
#include "MainWindow.h"
#include "Player.cpp"
#include "Math.cpp"
#include "GamePrivateMethods.cpp"
Game::Game(MainWindow& wnd, Graphics& gfx) :wnd(wnd), gfx(gfx), index(0), nPlayer(25)
{
srand((unsigned int)time(0));
}
void Game::Go()
{
	gfx.BeginDraw();
	
	gfx.SetBackground(98955);
	DrawFrame();
	ComposeFrame();
	gfx.EndDraw();
}
void Game::ComposeFrame()
{
	ProcessMouseInput();
	for (int i = 0;i < nPlayer;i++)
	{
		spritelist[i].MovePlayer(wnd.kbd);
	}
	CheckColission();
}
void Game::DrawFrame()
{
	gfx.TrasformPerspective(wnd.mouse, wnd.kbd);
	for (int x = 0;x < nPlayer;x++)
	{
		spritelist[x].DrawPlayer(gfx);
	}
}
bool Game::LoadRecources()
{
	int i = 0;
	for (;i < nPlayer;i++)
	{
		Player player(CreateRandomPlayerValues,i);
		spritelist.push_back(player);
		if (i == nPlayer-1)return true;
	}
	return false;
}

#include "Game.h"
#include "Macros.h"

bool Game::BallSelected()
{
	for (int i = 0;i < nPlayer;i++)
	{
		if (MouseIsInside)
		{
			index = i;
			return true;
		}
		
	}
	return false;
}
void Game::DeletePlayer()
{
	spritelist.erase(spritelist.begin() + index);
	nPlayer = nPlayer - 1;
}
void Game::AddPlayer()
{
	if (wnd.mouse.GetMouseState().DbClick)
	{
		MessageBeep(MB_OK);
		Player player(CreatePlayerValuesAtMousePosition);
		nPlayer++;
		spritelist.push_back(player);
		wnd.mouse.OnLMbuttonDbclickEnd();
	}
}
void Game::ConnectPlayer()
{
	for (int i = 0;i < nPlayer;i++)
	{
		gfx.DrawLine(spritelist[index].GetShape().point, spritelist[i].GetShape().point);
		spritelist[index].ChangeColor();
	}
}
void Game::ProcessMouseInput()
{
	AddPlayer();
	if (wnd.mouse.GetMouseState().click)
	{
		if (wnd.mouse.GetMouseState().LMbutton and BallSelected())
		{
			spritelist[index].MovePlayer(wnd.mouse);
			ConnectPlayer();
		}
		else if (wnd.mouse.GetMouseState().RMbutton and BallSelected())
		{
			DeletePlayer();
		}
	}
}
void Game::CheckColission()
{

	for (int i = 0;i < nPlayer-1;i++)
	       for(int j=i+1;j<nPlayer;j++)
		if (math.CalculateLenght(spritelist[j].GetShape().point, spritelist[i].GetShape().point) < (spritelist[i].GetShape().radiusX + spritelist[j].GetShape().radiusX) and spritelist[j].GetId() != spritelist[i].GetId())
		{
			float newX1 = spritelist[j].GetShape().point.x;
			float newY1 = spritelist[j].GetShape().point.y;
			float newX2 = spritelist[i].GetShape().point.x;
			float newY2 = spritelist[i].GetShape().point.y;
			float distance = math.CalculateLenght(spritelist[j].GetShape().point, spritelist[i].GetShape().point);
			float overlap = 0.5f * (distance - spritelist[j].GetShape().radiusX - spritelist[i].GetShape().radiusX);
			newX1 -= overlap * (newX1 - newX2) / distance;
			newY1 -= overlap * (newY1 - newY2) / distance;
			newX2 += overlap * (newX1 - newX2) / distance;
			newY2 += overlap * (newY1 - newY2) / distance;
			if (spritelist[i].GetMass() >= spritelist[j].GetMass())
			{
				spritelist[j].InvertX();
				spritelist[j].InvertY();
			}
			else {
				spritelist[i].InvertX();
				spritelist[i].InvertY();
			}
			spritelist[j].SetPosition(newX1, newY1);
			spritelist[i].SetPosition(newX2, newY2);
			spritelist[j].ChangeColor();
			spritelist[i].ChangeColor();
		}
	
}
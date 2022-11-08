#pragma once
#include "Player.h"
#include "Math.h"
#include "Macros.h"
class Game
{
	
	Math math;
	MainWindow& wnd;
	Graphics& gfx;
public:Game(MainWindow& wnd, Graphics& gfx);
	  void Go();
	  bool LoadRecources();
private: void ComposeFrame();
	     void DrawFrame();
		 bool BallSelected();
		 void ConnectPlayer();
		 void DeletePlayer();
		 void AddPlayer();
		 void ProcessMouseInput();
		 void CheckColission();
		 int nPlayer;
		 int index=0;
		 std::vector<Player> spritelist;
};
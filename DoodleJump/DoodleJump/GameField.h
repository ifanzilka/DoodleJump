#pragma once
#include "GameDoodleJump.h"
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;
class GameField :public GameDoodleJump
{

	RenderWindow app;//window
	
	Texture t1, t2, t3, t4;
	
	Sprite sBackground, sPlat, sPers;

	protected:
		void NextAnimation(point *plat);
		void drawGame(point *plat);
	
public:

	void StartGame();
	void EndGame();
	GameField();
	~GameField();
};


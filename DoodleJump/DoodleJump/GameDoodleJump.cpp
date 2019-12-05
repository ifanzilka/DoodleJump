#include "GameDoodleJump.h"


void GameDoodleJump::PlatformRandom(point *plat)
{
	//plaform random

	for (int i = 0; i < platforms; i++)
	{
		plat[i].x = rand() % width;
		plat[i].y = rand() % height;
	}

}

void GameDoodleJump::RightKey()
{

	x += 3;
	//sPers.setRotation(sPers.getRotation()+10);
	//sPers.setTexture(t4);
	//x += 24;
}

void GameDoodleJump::LeftKey()
{
	x -= 3;
}

void GameDoodleJump::Jump()
{
}

void GameDoodleJump::CheckPlatformAndBoder(point* plat)
{

	//check platform key

	for (int i = 0; i < platforms; i++)
	{
		if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
			&& (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
		{
			dy = -10;
		}


	}

	//check  border

	if (x > width)x = 0;
	if (x < -60) x = width;
}

GameDoodleJump::GameDoodleJump()
{
}


GameDoodleJump::~GameDoodleJump()
{
}

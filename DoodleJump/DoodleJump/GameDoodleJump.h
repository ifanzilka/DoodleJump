#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;
class GameDoodleJump
{
protected:

	int width = 400;//its image
	int height = 533;

	int platforms = 20;
	float kf = 1;


	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;

	struct  point
	{

		int x;
		int y;
	};

	void PlatformRandom(point *plat);
	void RightKey();
	void LeftKey();
	void Jump();
	void CheckPlatformAndBoder(point *plat);
	
public:
	GameDoodleJump();
	~GameDoodleJump();
};


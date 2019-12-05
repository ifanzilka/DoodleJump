#include "GameField.h"


void GameField::NextAnimation(point *plat)
{
	if (y < h)
	{
		for (int i = 0; i < platforms; i++)
		{
			y = h;
			plat[i].y = plat[i].y - dy;

			if (plat[i].y > height) { plat[i].y = 0; plat[i].x = rand() % width; }
		}




	}
}

void GameField::drawGame(point *plat)
{
	//draw
	sPers.setPosition(x, y);

	app.draw(sBackground);
	app.draw(sPers);
	for (int i = 0; i < platforms; i++)
	{
		sPlat.setPosition(plat[i].x, plat[i].y);
		app.draw(sPlat);

	}


	app.display();
}

void GameField::StartGame()
{
	point plat[20];

	PlatformRandom(plat);




	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed) app.close();


		}


		//keyboard
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			RightKey();
			sPers.setTexture(t4);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			LeftKey();
			sPers.setTexture(t3);

		}


		
		dy += 0.2;//jump
		y += dy;
		if (y > 500) dy = -10;



		// next animation
		NextAnimation(plat);
		CheckPlatformAndBoder(plat);


		
		drawGame(plat);

		
	}

	
}

GameField::GameField()
{
	srand(time(0));
	app.create(VideoMode(width, height), "Doodle Jump Game!", sf::Style::Close);
	app.setFramerateLimit(60);//cadr in sec


	//texture
	t1.loadFromFile("images/background.png");
	t2.loadFromFile("images/platform.png");
	t3.loadFromFile("images/doodle.png");
	t4.loadFromFile("images/doodle2.png");

	//set texture
	sBackground.setTexture(t1);
	sPlat.setTexture(t2);
	sPers.setTexture(t3);

	
	
}


GameField::~GameField()
{
}

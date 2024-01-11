#pragma once
#include "Global.h"
#include "Player.h"
#include "Stone.h"
#include "Sprite.h"

#include <vector>

class Game
{
public:
	Game();
	void play();

private:
	void handleInput();
	void update();
	void draw();

	sf::Clock m_clock;
};


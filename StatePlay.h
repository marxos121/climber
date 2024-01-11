#pragma once

#include "Sprite.h"
#include "BaseState.h"
#include "Player.h"
#include "Stone.h"
#include "Text.h"

#include <SFML/System/Clock.hpp>

class StatePlay : public BaseState {
public:
	StatePlay();
	void update(float elapsed) override;
	void render() override;
	void reset();

private:
	sf::View m_playerView;
	std::vector<std::pair<Sprite, Sprite>> m_walls;
	unsigned int m_nextToMove;
	unsigned int m_highestWall;

	Player m_player;
	bool m_gameOver;

	Stone m_stone;

	Text m_heightText;
	sf::Vector2i m_textCoords;

	//Private functions
	void updateHeight();
	void initNewWalls(std::pair<Sprite, Sprite>& newElem);
};
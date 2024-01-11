#include "StatePlay.h"

#include <SFML/Window/Keyboard.hpp>

#define DEBUG

StatePlay::StatePlay()
	: BaseState(StateType::Play), m_gameOver(false), m_textCoords({30, 30}), m_nextToMove(0), m_highestWall(6)
{
	m_heightText.setFont("main");
	m_heightText.setCharacterSize(30);
	m_heightText.setRotation(-15.f);

	m_playerView.setSize(Global::window.getSize().x, Global::window.getSize().y);
	for (int i = 0; i < 7; ++i) {
		auto& newElem = m_walls.emplace_back(std::make_pair(Sprite(), Sprite()));
		initNewWalls(newElem);
	}
	reset();
}

void StatePlay::update(float elapsed)
{
	if (m_gameOver) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			reset();
		}
		return;
	}

	m_player.handleInput();
	m_player.update(elapsed);
	m_playerView.setCenter({ (float)Global::window.getSize().x / 2, m_player.getPosition().y - (float)Global::window.getSize().y / 4 });

	m_stone.update(elapsed);

	auto stoneBounds = m_stone.getSprite().getGlobalBounds();

	for (const auto& collider : m_stone.getColliders()) {
		if (collider->getGlobalBounds().intersects(m_player.getSprite().getGlobalBounds())) {
			m_gameOver = true;
			m_player.setActive(false);
			return;
		}

	}
	if (stoneBounds.left < m_walls[0].first.getGlobalBounds().width ||
		stoneBounds.left + stoneBounds.width > m_walls[0].second.getGlobalBounds().left) {
		m_stone.setSpeed({ -m_stone.getSpeed().x, m_stone.getSpeed().y });
	}

	if (stoneBounds.top > (m_player.getSprite().getGlobalBounds().top + m_player.getSprite().getGlobalBounds().height)) {
		m_stone.initialize(m_player.getPosition().y);
	}

	if (m_walls[m_nextToMove].first.getGlobalBounds().top > (m_player.getSprite().getGlobalBounds().top + m_player.getSprite().getGlobalBounds().height)) {
		m_walls[m_nextToMove].first.setPosition(m_walls[m_highestWall].first.getPosition().x,
			m_walls[m_highestWall].first.getPosition().y - m_walls[m_highestWall].first.getGlobalBounds().height);
		m_walls[m_nextToMove].second.setPosition(m_walls[m_highestWall].second.getPosition().x,
			m_walls[m_highestWall].first.getPosition().y - m_walls[m_highestWall].first.getGlobalBounds().height);
		m_highestWall = m_nextToMove;
		m_nextToMove++;
		if (m_nextToMove > 6) {
			m_nextToMove = 0;
		}
	}

	updateHeight();
}

void StatePlay::render()
{
	Global::window.setView(m_playerView);

	for (auto beg = m_walls.begin(); beg != m_walls.end(); ++beg) {
		Global::window.draw(beg->first);
		Global::window.draw(beg->second);
	}

	m_player.draw();
	m_stone.draw();
	Global::window.draw(m_heightText);

#ifdef DEBUG
	for (const auto& collider : m_stone.getColliders()) {
		Global::window.draw(*collider);
	}
#endif
}

void StatePlay::reset()
{
	for (int i = 0; i != m_walls.size(); ++i) {
		m_walls[i].first.setPosition({ 0, Global::window.getSize().y - m_walls[i].first.getLocalBounds().height * (i + 1) });
		m_walls[i].second.setPosition({ (float)Global::window.getSize().x / 4 * 3,
			(float)Global::window.getSize().y - m_walls[i].second.getLocalBounds().height * (i + 1) });
	}
	m_nextToMove = 0;
	m_highestWall = 6;
	m_gameOver = false;

	m_player.reset();
	m_stone.initialize(Global::window.getSize().y / 4 * 3);
}

//Private functions
void StatePlay::updateHeight()
{
	m_heightText.setString(std::to_string(-static_cast<int>(m_player.getPosition().y) / 200) + " m");
	m_heightText.setPosition(Global::window.mapPixelToCoords(m_textCoords));
}

void StatePlay::initNewWalls(std::pair<Sprite, Sprite>& newElem)
{
	newElem.first.setTexture("wall");
	newElem.second.setTexture("wall");
	newElem.second.setTextureRect({ newElem.second.getTextureRect().width, 0,
		-newElem.second.getTextureRect().width, newElem.second.getTextureRect().height });
}
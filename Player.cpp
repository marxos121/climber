#include "Player.h"
#include "Sprite.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player()
	: Entity("player-default"),
	m_side(Side::Left), m_huggingWall(false)
{
}

void Player::reset()
{
	m_side = Side::Left;
	m_huggingWall = false;
	m_position.x = Global::window.getSize().x / 4;
	m_position.y = 0;
	m_speed = { 0.f, 0.f };
	m_sprite.setPosition(m_position);

	m_isActive = true;
}

void Player::handleInput()
{
	if (m_side == Side::Middle || !m_isActive) {
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_speed.y == 0.f)
		{
			m_speed.y = -400.f;
		}
		else if (m_speed.y > -1600.f)
		{
			m_speed.y *= 1.0005f;
		}
	}

	else
	{
		m_speed.y = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (m_side == Side::Left) {
				m_huggingWall = true;
			}
			else if (m_side == Side::Right) {
				m_side = Side::Middle;
				m_speed.x = -m_jumpSpeed;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (m_side == Side::Right) {
				m_huggingWall = true;
			}
			else if (m_side == Side::Left) {
				m_side = Side::Middle;
				m_speed.x = m_jumpSpeed;
			}
		}
	}

	if (m_huggingWall) {
		m_sprite.setTexture("player-hugging", true);
	}
	else {
		m_sprite.setTexture("player-default", true);
	}

}


void Player::update(float elapsed)
{
	if (!m_isActive) { return; }

	m_position.x += m_speed.x * elapsed;
	m_position.y += m_speed.y * elapsed;	//update just the score instead

	auto bounds = m_sprite.getGlobalBounds();

	if (bounds.left < Global::window.getSize().x / 4.f) 
	{
		m_position.x = Global::window.getSize().x / 4;
		m_side = Side::Left;
		m_speed.x = 0.f;
	} 
	else if (bounds.left + bounds.width > Global::window.getSize().x * 3.f / 4.f) {
		m_position.x = Global::window.getSize().x * 3 / 4 - bounds.width;
		m_side = Side::Right;
		m_speed.x = 0.f;
	}

	if (m_huggingWall && m_side == Side::Right) {
			m_position.x = Global::window.getSize().x * 3 / 4 - bounds.width;
	}

	m_sprite.setPosition(m_position);
	m_huggingWall = false;
}

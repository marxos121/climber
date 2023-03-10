#include "Entity.h"

#include <SFML/Graphics/RenderWindow.hpp>

Entity::Entity(sf::Vector2f pos, sf::Vector2f speed, sf::Texture& text)
	: m_position(pos), m_speed(speed)
{
	m_sprite.setTexture(text);
	m_sprite.setPosition(m_position);
}

void Entity::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Entity::update(float elapsed)
{
	m_position.x += m_speed.x * elapsed;
	m_position.y += m_speed.y * elapsed;

	m_sprite.setPosition(m_position);
}

sf::Sprite Entity::getSprite() const
{
	return m_sprite;
}

sf::Vector2f Entity::getPosition() const
{
	return m_position;
}

sf::Vector2f Entity::getSpeed() const
{
	return m_speed;
}

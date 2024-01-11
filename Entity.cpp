#include "Entity.h"
#include "Global.h"

Entity::Entity(const std::string& text, const sf::Vector2f& pos, const sf::Vector2f& speed)
	: m_sprite(&Global::textureManager), m_position(pos), m_speed(speed), m_isActive(true)
{
	m_sprite.setTexture(text);
	m_sprite.setPosition(m_position);
}

void Entity::draw()
{
	Global::window.draw(m_sprite);
}

void Entity::update(float elapsed)
{
	if (!m_isActive) { return; }

	auto initPosition = m_position;

	m_position.x += m_speed.x * elapsed;
	m_position.y += m_speed.y * elapsed;

	auto positionDelta = m_position - initPosition;

	for (auto& collider : m_colliders)
	{
		collider->move(positionDelta);
	}

	m_sprite.setPosition(m_position);
}

void Entity::setActive(bool active)
{
	m_isActive = active;
}

void Entity::setPosition(const sf::Vector2f& pos)
{
	m_position = pos; 
}

void Entity::setSpeed(const sf::Vector2f& speed)
{
	m_speed = speed;
}

bool Entity::getActive() const
{
	return m_isActive;
}

Sprite& Entity::getSprite()
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

const std::vector<sf::Shape*>& Entity::getColliders() const
{
	return m_colliders;
}

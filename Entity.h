#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <string>

namespace sf {
	class RenderWindow;
}

class Entity
{
public:
	Entity(sf::Vector2f pos, sf::Vector2f speed, sf::Texture& text);
	void draw(sf::RenderWindow& window);

	virtual void update(float elapsed);

	sf::Sprite getSprite() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSpeed() const;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_speed;
};


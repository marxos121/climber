#pragma once
#include "Sprite.h"

#include <SFML/Graphics/Shape.hpp>

#include <string>
#include <vector>

class Entity
{
public:
	Entity(const std::string& texture, 
		const sf::Vector2f& pos = sf::Vector2f(0,0), 
		const sf::Vector2f& speed = sf::Vector2f(0, 0));

	virtual void update(float elapsed);
	void draw();

protected:
	bool m_isActive;
	Sprite m_sprite;
	sf::Vector2f m_position;
	sf::Vector2f m_speed;

	std::vector<sf::Shape*> m_colliders;

public:
	//Setters and getters
	void setActive(bool active);
	void setPosition(const sf::Vector2f& pos);
	void setSpeed(const sf::Vector2f& speed);

	bool getActive() const;
	Sprite& getSprite();
	sf::Vector2f getPosition() const;
	sf::Vector2f getSpeed() const;

	const std::vector<sf::Shape*>& getColliders() const;
};


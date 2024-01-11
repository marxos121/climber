#include "Stone.h"
#include "TextureManager.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

Stone::Stone()
	: Entity("rock")
{
	m_colliders.push_back(new sf::RectangleShape({ 63.f, 150.f}));
	m_colliders.back()->setFillColor(sf::Color(255, 0, 0, 128));
	m_colliders.push_back(new sf::RectangleShape({ 90.f, 55.f }));
	m_colliders.back()->setFillColor(sf::Color(255, 0, 0, 128));
	m_colliders.push_back(new sf::RectangleShape({ 16.f, 37.f }));
	m_colliders.back()->setFillColor(sf::Color(255, 0, 0, 128));
	m_colliders.push_back(new sf::RectangleShape({ 23.f, 98.f }));
	m_colliders.back()->setFillColor(sf::Color(255, 0, 0, 128));

}


void Stone::initialize(float playerY)
{
	m_speed.x = (rand() % 4 == 0 ? (rand() % 200 + 200) : 0);
	m_speed.y = (rand() % 400 + 700);
	m_position.x = 160 + (rand() % 3) * 80;
	m_position.y = playerY - 2 * Global::window.getSize().y;
	m_sprite.setPosition(m_position);
	m_colliders[0]->setPosition(m_position);
	m_colliders[0]->move({ 72, 4 });
	m_colliders[1]->setPosition(m_position);
	m_colliders[1]->move({ 11, 90 });
	m_colliders[2]->setPosition(m_position);
	m_colliders[2]->move({ 54, 33 });
	m_colliders[3]->setPosition(m_position);
	m_colliders[3]->move({ 136, 40 });
}
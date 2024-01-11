#pragma once

#include <string>

#include <SFML/System/Vector2.hpp>

namespace sf {
	class Transformable;
}


enum class Collision {
	None = 0, Top, Right, Bottom, Left
};

template <typename T>
class Collider
{
public:
	Collider(const sf::Transformable& l_parent, 
		const T& l_shape, 
		const sf::Vector2f& l_offset = { 0.f, 0.f },
		const std::string& l_id = "");
	
	Collider(const Collider&) = delete;

	virtual bool collides(const Collider& other) = 0;

	const T& getShape() const;
	const sf::Transformable& getParent() const;
	std::string getId() const;
	sf::Vector2f getOffset() const;

	void setActive(bool l_active);
	bool getActive() const;

private:
	bool m_active;

	const T m_shape;
	const std::string m_id;
	const sf::Vector2f m_offset;
	const sf::Transformable& m_parent;
};

#include "Collider.inl"
#pragma once

#include "Collider.h"

struct Circle {
	float radius;
	sf::Vector2f center;	//Center on two dimensional axis
};

class CircleCollider : public Collider<Circle> {
public:
	CircleCollider(const sf::Transformable& l_parent,
		const Circle& l_shape,
		const sf::Vector2f& l_offset = { 0.f, 0.f },
		const std::string& l_id = "");

	bool collides(const Collider& other) override;
};
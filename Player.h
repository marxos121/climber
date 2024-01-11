#pragma once
#include "Entity.h"
#include "Global.h"

class Player : public Entity
{
	enum class Side {
		Left = 0, Middle, Right
	};

public:
	Player();
	void reset();
	void handleInput();
	void update(float elapsed) override;

private:
	Side m_side;
	bool m_huggingWall;

	const float m_jumpSpeed = 1200.f;
};


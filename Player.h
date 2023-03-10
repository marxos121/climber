#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	void update(float elapsed) override;

private:
	bool m_isAttached;	//Variable to determine whether the player can jump
	bool m_huggingWall;
};


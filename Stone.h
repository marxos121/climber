#pragma once
#include "Entity.h"

class Stone : public Entity
{
public:
	Stone();
	void update(float elapsed) override;
};


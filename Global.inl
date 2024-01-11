#include "Global.h"

template<typename T>
void Global::setOriginCenter(T& target)
{
	target.setOrigin(target.getGlobalBounds().width / 2, target.getGlobalBounds().height / 2);
}
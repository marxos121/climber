#include "Global.h"

#include "Sprite.h"
#include "Text.h"

template<>
void Global::setOriginCenter<sf::Text>(sf::Text& target)
{
	target.setOrigin(target.getGlobalBounds().left + target.getGlobalBounds().width / 2,
		target.getGlobalBounds().top + target.getGlobalBounds().height / 2);
}

template<>
void Global::setOriginCenter<Text>(Text& target)
{
	target.setOrigin(target.getGlobalBounds().left + target.getGlobalBounds().width / 2,
		target.getGlobalBounds().top + target.getGlobalBounds().height / 2);
}
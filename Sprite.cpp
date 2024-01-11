#include "Sprite.h"

Sprite::Sprite(ResourceManager<sf::Texture>* mgr)
	: ResourceUser<sf::Texture>(mgr)
{
}

void Sprite::setTexture(const std::string& texture, bool resetRect)
{
	if (texture == m_resourceName) { return; }
	notifyRelease();
	sf::Sprite::setTexture(*m_mgr->get(texture), resetRect);
	changeResource(texture);
}
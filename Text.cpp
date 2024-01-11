#include "Text.h"

Text::Text(ResourceManager<sf::Font>* mgr)
	: ResourceUser<sf::Font>(mgr)
{

}

void Text::setFont(const std::string& font) 
{
	notifyRelease();
	sf::Text::setFont(*m_mgr->get(font));
	m_resourceName = font;
}
#ifndef TEXT_H
#define TEXT_H

#include "ResourceUser.h"
#include "Global.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

template <typename T>
class ResourceManager;


class Text : public sf::Text, public ResourceUser<sf::Font> {
public:
	Text(ResourceManager<sf::Font>* mgr = &Global::fontManager);

	void setFont(const std::string& font);
};

#endif
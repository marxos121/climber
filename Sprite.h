#ifndef SPRITE_H
#define SPRITE_H

#include "ResourceUser.h"
#include "Global.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

template <typename T>
class ResourceManager;

class Sprite : public sf::Sprite, public ResourceUser<sf::Texture> {
public:
	Sprite(ResourceManager<sf::Texture>* mgr = &Global::textureManager);

	void setTexture(const std::string& texture, bool resetRect = false);
};

#endif
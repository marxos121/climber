#pragma once

#include "SoundManager.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "Window.h"
#include "StateManager.h"

class Sprite; class Text;

namespace sf {
	class Shape;
}


namespace Global {
	inline FontManager fontManager;
	inline TextureManager textureManager;
	inline SoundManager soundManager;
	inline GameWindow window;
	inline StateManager stateManager;


	template <typename T>
	void setOriginCenter(T& target);
	sf::Vector2f normalizeSpeed(sf::Vector2f currentSpeed, float maxSpeed);
};


#include "Global.inl"
#ifndef SOUND_H
#define SOUND_H


#include "ResourceUser.h"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


class Sound : public sf::Sound, public ResourceUser<sf::SoundBuffer> {
public:
	Sound(ResourceManager<sf::SoundBuffer>* mgr);

	void setBuffer(const std::string& buffer);
};


#endif
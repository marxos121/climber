#include "Sound.h"

Sound::Sound(ResourceManager<sf::SoundBuffer>* mgr)
	: ResourceUser<sf::SoundBuffer>(mgr)
{

}

void Sound::setBuffer(const std::string& buffer)
{
	notifyRelease();
	sf::Sound::setBuffer(*m_mgr->get(buffer));
	m_resourceName = buffer;
}

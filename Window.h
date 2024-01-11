#pragma once

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/String.hpp>

class GameWindow : public sf::RenderWindow
{
public:
	GameWindow() = default;
	GameWindow(sf::VideoMode  	mode,
		const sf::String& title,
		sf::Uint32  	style = sf::Style::Default);

	~GameWindow() = default;

	void toggleFullscreen();
	void updateWindowedSize();

	void setTitle(const sf::String& title);
	void setSize(const sf::Vector2u& size);

	bool isFullscreen() const;
	sf::Vector2u getWindowedSize() const;
	sf::Vector2f getScale() const;
	sf::String getTitle() const;

private:
	bool m_isFullscreen = false;
	sf::Vector2u m_windowedSize;
	sf::String m_title;
};


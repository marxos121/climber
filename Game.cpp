#include "Game.h"
#include "StatePlay.h"

#include <SFML/Window/Event.hpp>

Game::Game() {
	srand(int(time(NULL)));
	Global::textureManager.addPath("player-default", "./Assets/player-default.png");
	Global::textureManager.addPath("player-hugging", "./Assets/player-hugging.png");
	Global::textureManager.addPath("wall", "./Assets/wall.png");
	Global::textureManager.addPath("rock", "./Assets/rock.png");
	Global::fontManager.addPath("komikap", "./Assets/KOMIKAP.ttf"); 
	Global::fontManager.addPath("main", "./Assets/Vegur-Regular.otf");


	Global::stateManager.registerState<StatePlay>(StateType::Play);

}

void Game::play()
{
	Global::window.create({ 640, 900, 32 }, "Climber", sf::Style::Close);
	Global::stateManager.addState(StateType::Play);

	while (Global::window.isOpen()) {
		handleInput();
		update();
		draw();
	}
}

void Game::handleInput()
{
	sf::Event event;
	while (Global::window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			Global::window.close();
		}
	}
}

void Game::update()
{
	sf::Time elapsed = m_clock.restart();

	Global::stateManager.update(elapsed.asSeconds());
}

void Game::draw()
{
	Global::window.clear(sf::Color::White);
	Global::stateManager.render();
	Global::window.display();
}

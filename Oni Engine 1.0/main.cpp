#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

std::string title = "ONI ENGINE DEMO";

sf::Clock fpsclock;
double lasttime = 0.0f;
long framerate = 0;
int main(int argc, char** argv)
{
	


	int width = 800, height = 600;
	bool isFullscreen = false;

	if (argc > 1){
		std::cout << "Running with arguments: \n";
		int i = 1;
		while (i != argc){
			std::cout << argv[i] << '\n';
			if (strcmp(argv[i], "-setSize") == 0 && argc > (i + 2)){
				width	= atoi(argv[(i + 1)]);
				height	= atoi(argv[(i + 2)]);
			}

			i++;
		}
	}

	sf::RenderWindow window(sf::VideoMode(width, height), title);
	sf::View view;
	view.setSize(sf::Vector2f((width/2.0f), (height/2.0f)));
	view.setCenter((width/2.0f), (height/2.0f));
	window.setView(view);
	Map map("../resources/ignore/");
	Entity test;
	test.setPosition(sf::Vector2f(80.f, 80.f));
	test.loadSpritesheet("../resources/ignore/player.png", sf::Vector2i(16, 16));
	test.direction = Entity::RIGHT;
	while (window.isOpen())
	{
		sf::Event event;
		if (fpsclock.getElapsedTime().asSeconds() >= 1.0f){
			window.setTitle(title + " - FPS: " + std::to_string(framerate));
			framerate = 0;
			fpsclock.restart();
		}
			framerate++;
		// End of framerate code

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				if (test.direction == Entity::RIGHT)
					test.move(Entity::RIGHT);
				else{
					test.direction = Entity::RIGHT;
					//test.changeTexture(0);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				if (test.direction == Entity::DOWN)
					test.move(Entity::DOWN);
				else{
					test.direction = Entity::DOWN;
					//test.changeTexture(2);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				if (test.direction == Entity::LEFT)
					test.move(Entity::LEFT);
				else{
					test.direction = Entity::LEFT;
					//test.changeTexture(4);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				if (test.direction == Entity::UP)
					test.move(Entity::UP);
				else{
					test.direction = Entity::UP;
					//test.changeTexture(7);
				}
			}
		}
		// Update view to the players location.
		view.setCenter(test.getLocation().x, test.getLocation().y);
		// Update the windows view to the newly changed view.
		window.setView(view);

		window.clear(sf::Color::Black);
		window.draw(map.getSprite());
		window.draw(test.getSprite());
		window.display();
	}

	return 0;
}
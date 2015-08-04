#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

#define TITLE "ONI ENGINE DEMO"

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

	sf::RenderWindow window(sf::VideoMode(width, height), TITLE);
	sf::View view;
	view.setSize(sf::Vector2f(400, 300));
	view.setCenter((width/2), (height/2));
	window.setView(view);
	Map map("../resources/textures/");
	Entity test;
	test.loadTextures({
		"../resources/textures/test-right.png",
		"../resources/textures/test-down.png",
		"../resources/textures/test-left.png",
		"../resources/textures/test-up.png",
	});
	test.direction = Entity::RIGHT;
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				if (test.direction == Entity::RIGHT)
					test.move(Entity::RIGHT);
				else{
					test.direction = Entity::RIGHT;
					test.changeTexture(0);
				}

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				if (test.direction == Entity::DOWN)
					test.move(Entity::DOWN);
				else{
					test.direction = Entity::DOWN;
					test.changeTexture(1);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				if (test.direction == Entity::LEFT)
					test.move(Entity::LEFT);
				else{
					test.direction = Entity::LEFT;
					test.changeTexture(2);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				if (test.direction == Entity::UP)
					test.move(Entity::UP);
				else{
					test.direction = Entity::UP;
					test.changeTexture(3);
				}
			}
		}
		// Update view to the players location.
		view.setCenter(test.getLocation().x, test.getLocation().y);
		// Update the windows view to the newly changed view.
		window.setView(view);

		window.clear();
		window.draw(map.getSprite());
		window.draw(test.getSprite());
		window.display();
	}

	return 0;
}
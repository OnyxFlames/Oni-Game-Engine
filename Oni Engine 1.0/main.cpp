#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Map.h"

std::string title = "ONI ENGINE DEMO";

sf::Clock fpsclock;
double lasttime = 0.0f;
long framerate = 0;
bool collide(sf::Sprite lhs, sf::Sprite rhs);
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
				width = atoi(argv[(i + 1)]);
				height = atoi(argv[(i + 2)]);
			}
			if (strcmp(argv[i], "-setFPSLimit") == 0 && argc > (i + 1)){
				framerate = atoi(argv[(i + 1)]);
			}

			i++;
		}
	
	}
	else {
		std::cout << "Running with no extra arguments.\n";
	}

	sf::RenderWindow window(sf::VideoMode(width, height), title);
	window.setFramerateLimit(framerate);
	sf::View view;
	view.setSize(sf::Vector2f((width/2.0f), (height/2.0f)));
	view.setCenter((width/2.0f), (height/2.0f));
	window.setView(view);
	Map map("../resources/ignore/");
	Entity test;
	test.setPosition(sf::Vector2f(80.f, 80.f));
	test.loadSpritesheet("../resources/ignore/player.png", sf::Vector2i(16, 16));
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
					test.move(Entity::RIGHT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					test.move(Entity::DOWN);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
					test.move(Entity::LEFT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
					test.move(Entity::UP);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
				test.isMoving = true;
			}
			else
				test.isMoving = false;
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
	std::cout << "Closed." << std::endl;
	return 0;
}
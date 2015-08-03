#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Map
{
private:
	std::string collisionFile;
	std::string mapFile;
	std::string scriptFile;


	sf::Texture texture;
	sf::Sprite sprite;

	void init(std::string init);
public:
	Map(std::string mapDirectory);
	~Map();

	sf::Sprite getSprite();
};


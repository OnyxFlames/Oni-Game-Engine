#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity
{

private:
	
	float speed = 16.0f;
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector<sf::Texture> textureVec;
	sf::Vector2f position = sf::Vector2f(0, 0);		//Entities location in game/location drawn on screen
	void init(std::string init);
public:
	
	short direction = DOWN;

	Entity				();										//Uninitialized entity.
	Entity				(std::string textLocation);
	~Entity				();

	
	Entity setSpeed		(float speedValue);
	Entity setPosition	(float x, float y);
	Entity setPosition	(sf::Vector2f loc);
	Entity move			(int enumDirection);

	sf::Sprite getSprite();
	void loadTextures(std::initializer_list<std::string> lst);
	void changeTexture(short textureIndex);


	enum direction {

		UP		= 0x010,
		RIGHT	= 0x020,
		DOWN	= 0x030,
		LEFT	= 0x040,

	};
	
};


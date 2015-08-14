#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity
{

private:
	size_t textureIndex = 0;
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

	
	Entity setSpeed			(float speedValue);
	Entity setPosition		(float x, float y);
	Entity setPosition		(sf::Vector2f loc);
	Entity move				(int enumDirection);
	sf::Vector2f getLocation();


	sf::Sprite getSprite();
	void loadTextures(std::initializer_list<std::string> lst);
	void loadSpritesheet(std::string spritesheet, sf::Vector2i spriteDimensions, sf::Vector2i startLocation = sf::Vector2i(0, 0));
	void changeTexture(size_t textureIndex);

	enum direction {

		UP		= 0x010,
		RIGHT	= 0x020,
		DOWN	= 0x030,
		LEFT	= 0x040,

	};
};


#include "Entity.h"
#include <iostream>
Entity::Entity(){


}

Entity::Entity(std::string texLocation)
{
	init(texLocation);
}
void Entity::init(std::string init){
	texture.loadFromFile(init);
	sprite.setTexture(texture);
}
Entity::~Entity()
{
}


sf::Sprite Entity::getSprite()
{
	return sprite;
}

Entity Entity::setSpeed(float speedValue){
	speed = speedValue;
	return *this;
}

Entity Entity::setPosition(float x, float y)
{
	this->setPosition(sf::Vector2f(x, y));
	return *this;
}


Entity Entity::setPosition(sf::Vector2f loc)
{
	sprite.setPosition(loc);
	position = loc;
	return *this;
}

sf::Vector2f Entity::getLocation(){
	return position;
}

Entity Entity::move(int enumDirection){

	if (enumDirection == UP){
		if (direction == enumDirection){
			position.y -= speed;
			sprite.setPosition(position);
		}
		else {
			changeDirection(enumDirection);
		}
	}
	if (enumDirection == RIGHT){
		if (direction == enumDirection){
			position.x += speed;
			sprite.setPosition(position);
		}
		else {
			changeDirection(enumDirection);
		}
	}
	if (enumDirection == DOWN){
		if (direction == enumDirection){
			position.y += speed;
			sprite.setPosition(position);
		}
		else {
			changeDirection(enumDirection);
		}
	}
	if (enumDirection == LEFT){
		if (direction == enumDirection){
			position.x -= speed;
			sprite.setPosition(position);
		}
		else {
			changeDirection(enumDirection);
		}
	}
	return *this;
}
/* Deprecated */
void Entity::loadTextures(std::initializer_list<std::string> lst){
	std::cerr << "ERROR: loadTextures(std::initializer_list<std::string> lst) is deprecated!\n";
	for (auto str : lst){
		texture.loadFromFile(str);
		textureVec.push_back(texture);
	}
	sprite.setTexture(textureVec[0]);
}

void Entity::loadSpritesheet(std::string spritesheet, sf::Vector2i spriteDimensions, sf::Vector2i startLocation){
	spriteSize = spriteDimensions;
	texture.loadFromFile(spritesheet);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(startLocation, spriteDimensions));
}

void Entity::changeDirection(int newdirection){
	int runningIndex = 0;
	if (isMoving)
		runningIndex = 16;

	if (newdirection == DOWN){
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(runningIndex, 0), spriteSize));
		direction = newdirection;
	}
	else if (newdirection == RIGHT){
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(runningIndex, 16), spriteSize));
		direction = newdirection;
	}
	else if (newdirection == LEFT){
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(runningIndex, 32), spriteSize));
		direction = newdirection;
	}
	else if (newdirection == UP){
		sprite.setTextureRect(sf::IntRect(sf::Vector2i(runningIndex, 48), spriteSize));
		direction = newdirection;
	}
}

void Entity::changeTexture(size_t Index){
	std::cerr << "ERROR: changeTexture(size_t Index) is deprecated!\n";
	if (Index > (textureVec.size() - 1))
		exit(EXIT_FAILURE);
	textureIndex = Index;
	sprite.setTexture(textureVec[textureIndex]);
}
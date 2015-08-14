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
		position.y -= speed;
		sprite.setPosition(position);
	}
	if (enumDirection == RIGHT){
		position.x += speed;
		sprite.setPosition(position);
	}
	if (enumDirection == DOWN){
		position.y += speed;
		sprite.setPosition(position);
	}
	if (enumDirection == LEFT){
		position.x -= speed;
		sprite.setPosition(position);
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
	texture.loadFromFile(spritesheet);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(startLocation, spriteDimensions));
}

void Entity::changeTexture(size_t Index){
	std::cerr << "ERROR: changeTexture(size_t Index) is deprecated!\n";
	if (Index > (textureVec.size() - 1))
		exit(EXIT_FAILURE);
	textureIndex = Index;
	sprite.setTexture(textureVec[textureIndex]);
}
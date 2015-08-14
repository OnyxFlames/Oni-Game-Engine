#include "Map.h"


Map::Map(std::string mapDirectory)
{
	init(mapDirectory);
}
sf::Sprite Map::getSprite(){
	return sprite;
}
void Map::init(std::string init){
	collisionFile = init + "/map.coll";
	texture.loadFromFile(init + "/map.png");
	texture.setRepeated(true);
	sprite.setTexture(texture);
}
Map::~Map()
{
}

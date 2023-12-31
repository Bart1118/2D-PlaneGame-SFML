#include "gamestart.h"
Boom::Boom() 
{
	mDuration = sf::milliseconds(350);
	Load("animation/boom.png", 10);
	assert(IsLoaded());
	this->setFramesize(sf::Vector2i(93.2, 88.5));
}
Boom::~Boom()
{

}
#include "gamestart.h"
Explosion::Explosion()
{
	mus.openFromFile("music/boom.wav");
	Load("animation/explosion.png",7);
	assert(IsLoaded());
	this->setFramesize(sf::Vector2i(151, 161));
}
Explosion::~Explosion()
{

}
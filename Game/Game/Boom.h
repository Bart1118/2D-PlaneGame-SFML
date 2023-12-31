#pragma once
#include "VisibleGameObject.h"
#include "Animation.h"
class Boom :
	public Animation
{
public:
	Boom();
	virtual ~Boom();
	sf::Clock c;
private:
};
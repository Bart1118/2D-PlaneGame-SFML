#pragma once
#include "VisibleGameObject.h"
#include "Animation.h"
class Explosion :
	public Animation
{
public:
	Explosion();
	virtual ~Explosion();
	sf::Music mus;
private:
};
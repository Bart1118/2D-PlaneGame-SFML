#pragma once
#include "VisibleGameObject.h"
#include "Animation.h"
class Bullet :
	public VisibleGameObject
	//public Animation
{
public:
	Bullet();
	virtual ~Bullet();
	void Update(float elapsedTime);
	float _velocity_bullet_y;
	sf::Music music;
private:
};
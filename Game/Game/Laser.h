#pragma once
#include "VisibleGameObject.h"
class Laser :
	public VisibleGameObject
{
public:
	Laser();
	virtual ~Laser();
	void Update(float elapsedTime);
	float _velocity_laser_y;
	int account;
	sf::Music music;
private:
	
};
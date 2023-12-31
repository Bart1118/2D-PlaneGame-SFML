#pragma once
#include "VisibleGameObject.h"
class EnemyHealth :
	public VisibleGameObject
{
public:
	EnemyHealth();
	virtual ~EnemyHealth();
	void Update(float elapsedTime);
private:
	sf::RectangleShape rect;
};
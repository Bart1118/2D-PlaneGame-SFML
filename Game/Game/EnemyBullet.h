#pragma once
#include "VisibleGameObject.h"
class EnemyBullet :
	public VisibleGameObject
{
public:
	EnemyBullet();
	virtual ~EnemyBullet();
	void Update(float elapsedTime);
	float _velocity_enemybullet_y;
private:
};
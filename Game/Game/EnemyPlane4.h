#pragma once
#include "VisibleGameObject.h"
class EnemyPlane4 :
	public VisibleGameObject
{
public:
	EnemyPlane4();
	virtual ~EnemyPlane4();
	void Update(float elapsedTime);
	int blood;
	std::string name;
	int hittime;
	sf::Text text;
private:
	float _velocity;  //速度
	float _angle;  //移动的方向
	float LinearVelocityX(float angle); //水平线速度
	float LinearVelocityY(float angle);  //垂直线速度
};
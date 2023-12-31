#pragma once
#include "VisibleGameObject.h"
class BossBullet :
	public VisibleGameObject
{
public:
	BossBullet();
	virtual ~BossBullet();
	void Update(float elapsedTime);
private:
	float _velocity;  //速度
	float _angle;  //移动的方向
	float _elapsedTimeSinceStart;  //游戏总时间;
	float LinearVelocityX(float angle); //水平线速度
	float LinearVelocityY(float angle);  //垂直线速度
};
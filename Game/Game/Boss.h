#pragma once
#include "VisibleGameObject.h"
class Boss :
	public VisibleGameObject
{
public:
	Boss();
	virtual ~Boss();
	void Update(float elapsedTime);
	int blood;
	std::string name;
	int hittime;
	sf::Text text;
	sf::Music music1;
	sf::Music music2;
	sf::Music music_back;
private:
	float _velocity;  //速度
	float _angle;  //移动的方向
	float LinearVelocityX(float angle); //水平线速度
	float LinearVelocityY(float angle);  //垂直线速度
};
#pragma once
#include "VisibleGameObject.h"
class Son :
	public VisibleGameObject
{
public:
	Son();
	virtual ~Son();
	void Update(float elapsedTime);
	int blood;
	std::string name;
	int hittime;
	sf::Text text;
	std::string number;
private:
	float _velocity;  //�ٶ�
	float _angle;  //�ƶ��ķ���
	float LinearVelocityX(float angle); //ˮƽ���ٶ�
	float LinearVelocityY(float angle);  //��ֱ���ٶ�
};
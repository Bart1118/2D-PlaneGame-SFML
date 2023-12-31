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
	float _velocity;  //�ٶ�
	float _angle;  //�ƶ��ķ���
	float LinearVelocityX(float angle); //ˮƽ���ٶ�
	float LinearVelocityY(float angle);  //��ֱ���ٶ�
};
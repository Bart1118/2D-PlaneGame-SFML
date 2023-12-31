#pragma once
#include "VisibleGameObject.h"
class EnemyPlane3 :
	public VisibleGameObject
{
public:
	EnemyPlane3();
	virtual ~EnemyPlane3();
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
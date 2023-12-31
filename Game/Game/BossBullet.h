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
	float _velocity;  //�ٶ�
	float _angle;  //�ƶ��ķ���
	float _elapsedTimeSinceStart;  //��Ϸ��ʱ��;
	float LinearVelocityX(float angle); //ˮƽ���ٶ�
	float LinearVelocityY(float angle);  //��ֱ���ٶ�
};
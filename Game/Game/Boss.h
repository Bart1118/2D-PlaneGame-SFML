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
	float _velocity;  //�ٶ�
	float _angle;  //�ƶ��ķ���
	float LinearVelocityX(float angle); //ˮƽ���ٶ�
	float LinearVelocityY(float angle);  //��ֱ���ٶ�
};
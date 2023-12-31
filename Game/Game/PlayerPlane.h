#pragma once
#include "VisibleGameObject.h"
#include "Bullet.h"
class PlayerPlane :public VisibleGameObject
{
public:
	PlayerPlane(void);
	~PlayerPlane(void);
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow &rw);
	float GetVelocity()const;
	float GetVelocity_y()const;
	int hit;
	int med;
	sf::Music music;
	sf::Music music_back1;
	sf::Music music_back2;
private:
	int i;
	int bullet_account;
	float _velocity;
	float _maxVelocity;
	float _velocity_y;
	float _maxVelocity_y;
};
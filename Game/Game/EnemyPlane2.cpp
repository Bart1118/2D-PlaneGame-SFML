#include "gamestart.h"
//float EnemyPlane2::counttime(0);
EnemyPlane2::EnemyPlane2() : _velocity(230.0f), blood(20), hittime(0), _angle(std::rand() % 360)
{
	Load("image/enemyplane2.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	//std::srand((unsigned)time(NULL));
}
EnemyPlane2::~EnemyPlane2()
{
}
void EnemyPlane2::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 60);
		Game::GetWindow().draw(text);
		EnemyHealth* health2 = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("EnemyHealth2" + Game::level));
		health2->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		health2->GetRect().setSize(sf::Vector2f(blood*4.0, 13));
		if (Operate::clock.getElapsedTime() < sf::seconds(3.0f)){ return; }
		float moveAmount = _velocity * elapsedTime;
		float moveByX = LinearVelocityX(_angle) * moveAmount;
		float moveByY = LinearVelocityY(_angle) * moveAmount;
		if (GetPosition().x + moveByX <= 0 + GetWidth() / 2 - 43
			|| GetPosition().x + GetWidth() / 2 + moveByX >= 800 - 35)
		{
			_angle = 360.0f - _angle;
			if (_angle > 260.0f && _angle < 280.0f)
				_angle += 20.0f;
			if (_angle > 80.0f && _angle < 100.0f)
				_angle += 20.0f;
			moveByX = -moveByX;
		}
		if (GetPosition().y + moveByY <= 0 + GetHeight() / 2 - 40 || GetPosition().y + GetHeight() / 2 + moveByY >= 300 - 30)
		{
			_angle = 180 - _angle;
			moveByY = -moveByY;
		}
		GetSprite().move(moveByX, moveByY);
		//std::cout << "enemy2 health:" << this->blood << " ";
		if (this->blood <= 0){ 
			Explosion *explosion2 = new Explosion();
			(Game::GetGameObjectManager().Add("Explosion2", explosion2));
			explosion2->mus.play();
			explosion2->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("EnemyHealth2" + Game::level));  (Game::GetGameObjectManager().Remove("enemybullet2" + Game::level)); (Game::GetGameObjectManager().Remove("Enemy2" + Game::level)); 
		}
	}
	EnemyBullet* enemybullet2 = dynamic_cast<EnemyBullet*>(Game::GetGameObjectManager().Get("enemybullet2" + Game::level));
	if (enemybullet2 != NULL)
	{
		enemybullet2->_velocity_enemybullet_y = 0.8f;

		if (enemybullet2->GetPosition().y - this->GetHeight() / 2 >= 600)
		{
			enemybullet2->SetPosition(this->GetSprite().getPosition().x + 32, this->GetSprite().getPosition().y + 10);
		}
		//}
		enemybullet2->GetSprite().move(0, enemybullet2->_velocity_enemybullet_y);
		//enemybullet2->Update();
	}
}
float EnemyPlane2::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float EnemyPlane2::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
#include "gamestart.h"
EnemyPlane1::EnemyPlane1() : _velocity(230.0f), blood(20), hittime(0), _angle(std::rand() % 360)
{
	Load("image/enemyplane1.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	std::srand((unsigned)time(NULL));
}
EnemyPlane1::~EnemyPlane1()
{
	
}
void EnemyPlane1::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y-60);
		Game::GetWindow().draw(text);
		EnemyHealth* health1 = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("EnemyHealth1" + Game::level));
		health1->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		health1->GetRect().setSize(sf::Vector2f(blood*4.0,13));
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
		//std::cout << "enemy1 health:" << this->blood << " ";
		if (this->blood <= 0)
		{
			Explosion *explosion1 = new Explosion();
			(Game::GetGameObjectManager().Add("Explosion1", explosion1));
			explosion1->mus.play();
			explosion1->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("EnemyHealth1" + Game::level)); (Game::GetGameObjectManager().Remove("enemybullet1" + Game::level)); (Game::GetGameObjectManager().Remove("Enemy1" + Game::level)); //(Game::GetGameObjectManager().Remove("Explosion"));
		}
	}
	EnemyBullet* enemybullet1 = dynamic_cast<EnemyBullet*>(Game::GetGameObjectManager().Get("enemybullet1" + Game::level));
	if (enemybullet1 != NULL)
	{
		enemybullet1->_velocity_enemybullet_y = 0.8f;

		if (enemybullet1->GetPosition().y - this->GetHeight() / 2 >= 600)
		{
			enemybullet1->SetPosition(this->GetSprite().getPosition().x + 32, this->GetSprite().getPosition().y + 10);
		}
		//}
		enemybullet1->GetSprite().move(0, enemybullet1->_velocity_enemybullet_y);
		//enemybullet1->Update();
	}
}
float EnemyPlane1::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float EnemyPlane1::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
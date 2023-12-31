#include "gamestart.h"
//float EnemyPlane3::counttime(0);
EnemyPlane3::EnemyPlane3() : _velocity(230.0f), blood(20), hittime(0), _angle(std::rand() % 360)
{
	Load("image/enemyplane3.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	//std::srand((unsigned)time(NULL));
}
EnemyPlane3::~EnemyPlane3()
{
}
void EnemyPlane3::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 60);
		Game::GetWindow().draw(text);
		EnemyHealth* health3 = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("EnemyHealth3" + Game::level));
		health3->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		health3->GetRect().setSize(sf::Vector2f(blood*4.0, 13));
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
		//std::cout << "enemy3 health:" << this->blood << " ";
		if (this->blood <= 0)
		{ 
			Explosion *explosion3 = new Explosion();
			(Game::GetGameObjectManager().Add("Explosion3", explosion3));
			explosion3->mus.play();
			explosion3->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("EnemyHealth3" + Game::level));  (Game::GetGameObjectManager().Remove("enemybullet3" + Game::level)); (Game::GetGameObjectManager().Remove("Enemy3" + Game::level)); 
		}
		EnemyBullet* enemybullet3 = dynamic_cast<EnemyBullet*>(Game::GetGameObjectManager().Get("enemybullet3" + Game::level));
		if (enemybullet3 != NULL)
		{
			enemybullet3->_velocity_enemybullet_y = 0.8f;

			if (enemybullet3->GetPosition().y - this->GetHeight() / 2 >= 600)
			{
				enemybullet3->SetPosition(this->GetSprite().getPosition().x + 32, this->GetSprite().getPosition().y + 10);
			}
			//}
			enemybullet3->GetSprite().move(0, enemybullet3->_velocity_enemybullet_y);
			//enemybullet3->Update();
		}
	}
	//EnemyPlane3* enemy3 = dynamic_cast<EnemyPlane3*>(Game::GetGameObjectManager().Get("Enemy3"));
}
float EnemyPlane3::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float EnemyPlane3::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
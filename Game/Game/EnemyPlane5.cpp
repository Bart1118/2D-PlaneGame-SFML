#include "gamestart.h"
//float EnemyPlane5::counttime(0);
EnemyPlane5::EnemyPlane5() : _velocity(230.0f), blood(20), hittime(0), _angle(std::rand() % 360)
{
	Load("image/enemyplane5.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	//std::srand((unsigned)time(NULL));
}
EnemyPlane5::~EnemyPlane5()
{
}
void EnemyPlane5::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 60);
		Game::GetWindow().draw(text);
		EnemyHealth* health5 = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("EnemyHealth5" + Game::level));
		health5->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		health5->GetRect().setSize(sf::Vector2f(blood*4.0, 13));
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
		//std::cout << "enemy5 health:" << this->blood << " ";
		if (this->blood <= 0)
		{
			Explosion *explosion5 = new Explosion();
			explosion5->mRepeat = false;
			(Game::GetGameObjectManager().Add("Explosion5", explosion5));
			explosion5->mus.play();
			explosion5->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("EnemyHealth5" + Game::level));  (Game::GetGameObjectManager().Remove("enemybullet5" + Game::level)); (Game::GetGameObjectManager().Remove("Enemy5" + Game::level));
		}
		EnemyBullet* enemybullet5 = dynamic_cast<EnemyBullet*>(Game::GetGameObjectManager().Get("enemybullet5" + Game::level));
		if (enemybullet5 != NULL)
		{
			enemybullet5->_velocity_enemybullet_y = 0.8f;

			if (enemybullet5->GetPosition().y - this->GetHeight() / 2 >= 600)
			{
				enemybullet5->SetPosition(this->GetSprite().getPosition().x + 32, this->GetSprite().getPosition().y + 10);
			}
			//}
			enemybullet5->GetSprite().move(0, enemybullet5->_velocity_enemybullet_y);
		}
	}
}
float EnemyPlane5::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float EnemyPlane5::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
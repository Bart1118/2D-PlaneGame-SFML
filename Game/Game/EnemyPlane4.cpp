#include "gamestart.h"
//float EnemyPlane4::counttime(0);
EnemyPlane4::EnemyPlane4() : _velocity(230.0f), blood(20), hittime(0), _angle(std::rand() % 360)
{
	Load("image/enemyplane4.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	//std::srand((unsigned)time(NULL));
}
EnemyPlane4::~EnemyPlane4()
{
}
void EnemyPlane4::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 60);
		Game::GetWindow().draw(text);
		EnemyHealth* health4 = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("EnemyHealth4" + Game::level));
		health4->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		health4->GetRect().setSize(sf::Vector2f(blood*4.0, 13));
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
		//std::cout << "enemy4 health:" << this->blood << " ";
		if (this->blood <= 0)
		{
			Explosion *explosion4 = new Explosion();
			(Game::GetGameObjectManager().Add("Explosion4", explosion4));
			explosion4->mus.play();
			explosion4->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("EnemyHealth4" + Game::level));  (Game::GetGameObjectManager().Remove("enemybullet4" + Game::level)); (Game::GetGameObjectManager().Remove("Enemy4" + Game::level));
		}
		EnemyBullet* enemybullet4 = dynamic_cast<EnemyBullet*>(Game::GetGameObjectManager().Get("enemybullet4" + Game::level));
		if (enemybullet4 != NULL)
		{
			enemybullet4->_velocity_enemybullet_y = 0.8f;

			if (enemybullet4->GetPosition().y - this->GetHeight() / 2 >= 600)
			{
				enemybullet4->SetPosition(this->GetSprite().getPosition().x + 32, this->GetSprite().getPosition().y + 10);
			}
			//}
			enemybullet4->GetSprite().move(0, enemybullet4->_velocity_enemybullet_y);
			//enemybullet3->Update();
		}
	}
	//EnemyPlane4* enemy3 = dynamic_cast<EnemyPlane4*>(Game::GetGameObjectManager().Get("Enemy3"));
}
float EnemyPlane4::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float EnemyPlane4::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
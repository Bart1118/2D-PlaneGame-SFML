#include "gamestart.h"
Son::Son() : _velocity(230.0f), blood(15), hittime(0), _angle(std::rand() % 360), number("0")
{
	Load("image/son.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	std::srand((unsigned)time(NULL));
}
Son::~Son()
{

}
void Son::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 60);
		Game::GetWindow().draw(text);
		EnemyHealth* health = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("SonHealth"+number));
		health->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		health->GetRect().setSize(sf::Vector2f(blood*4.0, 13));
		if (Operate::clock.getElapsedTime() < sf::seconds(3.0f)){ return; }
		float moveAmount = _velocity * elapsedTime;
		float moveByX = LinearVelocityX(_angle) * moveAmount;
		float moveByY = LinearVelocityY(_angle) * moveAmount;
		if (GetPosition().x + moveByX <= 0 + GetWidth() / 2 - 25
			|| GetPosition().x + GetWidth() / 2 + moveByX >= 800 - 15)
		{
			_angle = 360.0f - _angle;
			if (_angle > 260.0f && _angle < 280.0f)
				_angle += 20.0f;
			if (_angle > 80.0f && _angle < 100.0f)
				_angle += 20.0f;
			moveByX = -moveByX;
		}
		if (GetPosition().y + moveByY <= 0 + GetHeight() / 2 - 20 || GetPosition().y + GetHeight() / 2 + moveByY >= 300 - 10)
		{
			_angle = 180 - _angle;
			moveByY = -moveByY;
		}
		GetSprite().move(moveByX, moveByY);
		//std::cout << "son health:" << this->blood << " ";
		if (this->blood <= 0)
		{
			Explosion *explosion = new Explosion();
			(Game::GetGameObjectManager().Add("Explosion" + number, explosion));
			explosion->mus.play();
			explosion->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("SonHealth" + number)); (Game::GetGameObjectManager().Remove("SonBullet" + number)); (Game::GetGameObjectManager().Remove("Son" + number));
		}
	}
	EnemyBullet* enemybullet = dynamic_cast<EnemyBullet*>(Game::GetGameObjectManager().Get("SonBullet" + number));
	if (enemybullet != NULL)
	{
		enemybullet->_velocity_enemybullet_y = 0.8f;

		if (enemybullet->GetPosition().y - this->GetHeight() / 2 >= 600)
		{
			enemybullet->SetPosition(this->GetSprite().getPosition().x + 32, this->GetSprite().getPosition().y + 10);
		}
		//}
		enemybullet->GetSprite().move(0, enemybullet->_velocity_enemybullet_y);
		//enemybullet1->Update();
	}
}
float Son::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float Son::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
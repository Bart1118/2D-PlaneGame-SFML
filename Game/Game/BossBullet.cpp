#include "gamestart.h"
BossBullet::BossBullet() : _velocity(100.0f),
_elapsedTimeSinceStart(0.0f), _angle(std::rand() % 360)
{
	Load("image/BossBullet.png");
	assert(IsLoaded());
	std::srand((unsigned)time(NULL));
}
BossBullet::~BossBullet()
{

}
void BossBullet::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;
	float moveAmount = _velocity * elapsedTime;
	float moveByX = LinearVelocityX(_angle) * moveAmount;
	float moveByY = LinearVelocityY(_angle) * moveAmount;
	if (GetPosition().x + moveByX <= 0 + GetWidth() / 2 - 30
		|| GetPosition().x + GetWidth() / 2 + moveByX >= 800 - 15)
	{
		_angle = 360.0f - _angle;
		if (_angle > 260.0f && _angle < 280.0f)
			_angle += 20.0f;
		if (_angle > 80.0f && _angle < 100.0f)
			_angle += 20.0f;
		moveByX = -moveByX;
	}
	if (GetPosition().y + moveByY <= 0 + GetHeight() / 2 - 30 || GetPosition().y + GetHeight() / 2 + moveByY >= 600 - 15)
	{
		_angle = 180 - _angle;
		moveByY = -moveByY;
	}
	GetSprite().move(moveByX, moveByY);
	PlayerPlane* player = dynamic_cast<PlayerPlane*>(Game::GetGameObjectManager().Get("Player"));
	if (player != NULL)
	{
		sf::Rect<float>e0BB = player->GetBoundingRect();
		if (e0BB.intersects(GetBoundingRect()))
		{
			Boom *boom = new Boom();
			(Game::GetGameObjectManager().Add("Boom", boom));
			boom->SetPosition(player->GetSprite().getPosition().x - 47, player->GetSprite().getPosition().y - 30);
			player->hit++;
			if (player->hit >= 90){ player->med--; player->hit = 0; (Game::GetGameObjectManager().Remove("Boom")); }
		}

	}
}
float BossBullet::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float BossBullet::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
#include "gamestart.h"
PlayerPlane::PlayerPlane(void) :_velocity(0.0), _velocity_y(0.0), _maxVelocity(450.0f), _maxVelocity_y(500.0f), hit(0), med(6)
{
	music.openFromFile("music/enemy.wav");
	music_back1.openFromFile("music/level_1.wav");
	music_back2.openFromFile("music/level_2.wav");
	Load("image/plane.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}
PlayerPlane::~PlayerPlane(void)
{

}
void PlayerPlane::Draw(sf::RenderWindow &rw)
{
	VisibleGameObject::Draw(rw);
}
float PlayerPlane::GetVelocity()const
{
	return _velocity;
}
float PlayerPlane::GetVelocity_y()const
{
	return _velocity_y;
}
void PlayerPlane::Update(float elapsedTime)
{
	PlayerHealth *health = dynamic_cast<PlayerHealth*>(Game::GetGameObjectManager().Get("PlayerHealth"));
	PlayerStars *stars = dynamic_cast<PlayerStars*>(Game::GetGameObjectManager().Get("PlayerStars"));
	if (Operate::clock.getElapsedTime() < sf::seconds(3.0f))
	{ sf::Font font; font.loadFromFile("arial.ttf"); sf::Text text; text.setFont(font); text.setString("GET READY!\n" + std::to_string(3.0f-Operate::clock.getElapsedTime().asSeconds())); text.setFillColor(sf::Color::Red); text.setPosition(250, 50); Game::GetWindow().draw(text); return; }
	if ((Operate::clock.getElapsedTime() > sf::seconds(3.0f) && (Operate::clock.getElapsedTime() < sf::seconds(3.0f) + sf::seconds(elapsedTime))))music.play();
	if (Operate::clock.getElapsedTime() > sf::seconds(3.5f) && Operate::clock.getElapsedTime() < sf::seconds(3.5f) + sf::seconds(elapsedTime)&&Game::LEVEL==1)music_back1.play();
	if (Operate::clock.getElapsedTime() > sf::seconds(3.5f) && Operate::clock.getElapsedTime() < sf::seconds(3.5f) + sf::seconds(elapsedTime) && Game::LEVEL == 2)music_back2.play();
	if (this->med>=5 && this->med < 6){ health->Load("image/playerhealth5.png"); }
	if (this->med>=4 && this->med < 5){ health->Load("image/playerhealth4.png"); }
	if (this->med>=3 && this->med < 4){ health->Load("image/playerhealth3.png"); }
	if (this->med>=2 && this->med < 3){ health->Load("image/playerhealth2.png"); }
	if (this->med>=1 && this->med < 2){ health->Load("image/playerhealth1.png"); }
	Laser *laser = dynamic_cast<Laser*>(Game::GetGameObjectManager().Get("laser"));
	if (laser->account == 2)stars->Load("image/star1.png");
	if (laser->account == 1)stars->Load("image/star0.png");
	if (Game::operatestate == Game::Mousing)
	{ 
		GetSprite().setPosition(sf::Mouse::getPosition(Game::GetWindow()).x, sf::Mouse::getPosition(Game::GetWindow()).y); 
		Bullet* bullet = dynamic_cast<Bullet*>(Game::GetGameObjectManager().Get("bullet"));
		bullet->music.pause();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bullet->music.play();
			bullet->_velocity_bullet_y = -3.8f;
			if (bullet->GetPosition().y - this->GetHeight() / 2 <= 0)
			{
				bullet->SetPosition(this->GetSprite().getPosition().x - 8.5, this->GetSprite().getPosition().y - 23);
			}
		}
		sf::Vector2f pos = this->GetPosition();
		if (pos.x < GetSprite().getLocalBounds().width / 2){ sf::Mouse::setPosition(sf::Vector2i(pos.x +5, pos.y), Game::GetWindow()); }
		if (pos.x>(800 - GetSprite().getLocalBounds().width / 2)){ sf::Mouse::setPosition(sf::Vector2i(pos.x-5, pos.y), Game::GetWindow()); }
		if (pos.y<GetSprite().getLocalBounds().height / 2){ sf::Mouse::setPosition(sf::Vector2i(pos.x, pos.y+5), Game::GetWindow()); }
		if (pos.y>(600 - GetSprite().getLocalBounds().height / 2)){ sf::Mouse::setPosition(sf::Vector2i(pos.x, pos.y-5), Game::GetWindow()); }
		bullet->GetSprite().move(0, bullet->_velocity_bullet_y);
		Laser* laser = dynamic_cast<Laser*>(Game::GetGameObjectManager().Get("laser"));
		if (laser != NULL)
		{
			if (laser->account == 0){ laser->SetPosition(0, 700); laser->music.pause(); }
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				if (laser->music.getStatus() != sf::Music::Status::Playing)laser->music.play();
				laser->_velocity_laser_y = -1.6f;
				if (laser->GetPosition().y - this->GetHeight() / 2 <= 0)
				{
					laser->music.setPlayingOffset(sf::seconds(0));
					laser->SetPosition(0, 700);
					laser->account -= 1;
				}
			}
			laser->GetSprite().move(0, laser->_velocity_laser_y);
		}
	}
	else if (Game::operatestate == Game::Keyboarding)
	{
		Bullet* bullet = dynamic_cast<Bullet*>(Game::GetGameObjectManager().Get("bullet"));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			_velocity -= 2.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			_velocity += 2.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			_velocity_y -= 2.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			_velocity_y += 2.0f;
		}
		if (_velocity > _maxVelocity)//如果弹板速度大于最大速度，就让其等于最大速度，最小速度也同理可得
			_velocity = _maxVelocity;
		if (_velocity < -_maxVelocity)
			_velocity = -_maxVelocity;
		if (_velocity_y > _maxVelocity_y)//如果弹板速度大于最大速度，就让其等于最大速度，最小速度也同理可得
			_velocity_y = _maxVelocity_y;
		if (_velocity_y < -_maxVelocity_y)
			_velocity_y = -_maxVelocity_y;
		sf::Vector2f pos = this->GetPosition();
		if (pos.x < GetSprite().getLocalBounds().width / 2){ if (_velocity<0)_velocity = -_velocity*0.5; }
		if (pos.x>(800 - GetSprite().getLocalBounds().width / 2)){ if (_velocity>0)_velocity = -_velocity*0.5; }
		if (pos.y<GetSprite().getLocalBounds().height / 2){ if (_velocity_y<0)_velocity_y = -_velocity_y*0.5; }
		if (pos.y>(600 - GetSprite().getLocalBounds().height / 2)){ if (_velocity_y>0)_velocity_y = -_velocity_y*0.5; }
		GetSprite().move(_velocity* elapsedTime, _velocity_y* elapsedTime);
		bullet->music.pause();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bullet->music.play();
			bullet->_velocity_bullet_y = -3.8f;
			if (bullet->GetPosition().y - this->GetHeight() / 2 <= 0)
			{
				bullet->SetPosition(this->GetSprite().getPosition().x - 8.5, this->GetSprite().getPosition().y - 23);
			}
			
		}
		bullet->GetSprite().move(0, bullet->_velocity_bullet_y);
		Laser* laser = dynamic_cast<Laser*>(Game::GetGameObjectManager().Get("laser"));
		if (laser != NULL)
		{
			if (laser->account == 0){ laser->SetPosition(0, 700); laser->music.pause(); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
			{
				if (laser->music.getStatus() != sf::Music::Status::Playing)laser->music.play();
				laser->_velocity_laser_y = -1.6f;
				if (laser->GetPosition().y - this->GetHeight() / 2 <= 0)
				{
					laser->music.setPlayingOffset(sf::seconds(0));
					laser->SetPosition(0, 700);
					laser->account -= 1;
				}
			}
			laser->GetSprite().move(0, laser->_velocity_laser_y);
		}
	}
}
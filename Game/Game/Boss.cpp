#include "gamestart.h"
Boss::Boss() : _velocity(25.0f),blood(500), hittime(0), _angle(std::rand() % 360)
{
	music1.openFromFile("music/boss.wav");
	music2.openFromFile("music/son.wav");
	music2.setLoop(true);
	music_back.openFromFile("music/boss_music.wav");
	music_back.setLoop(true);
	Load("image/boss.png");
	extern sf::Font font;
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	assert(IsLoaded());
	std::srand((unsigned)time(NULL));
}
Boss::~Boss()
{

}
void Boss::Update(float elapsedTime)
{
	if (this != NULL)
	{
		text.setString("HP:" + std::to_string(blood));
		text.setPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 60);
		Game::GetWindow().draw(text);
		EnemyHealth* bosshealth = dynamic_cast<EnemyHealth*>(Game::GetGameObjectManager().Get("BossHealth"));
		bosshealth->SetPosition(this->GetSprite().getPosition().x, this->GetSprite().getPosition().y - 18);
		bosshealth->GetRect().setSize(sf::Vector2f(blood/5.0*3, 13));
		if (Operate::clock.getElapsedTime() < sf::seconds(3.0f)){ if (music1.getStatus() != sf::Music::Status::Playing)music1.play(); return; }
		if (Operate::clock.getElapsedTime() > sf::seconds(3.0f) && Operate::clock.getElapsedTime() < sf::seconds(3.0f) + sf::seconds(elapsedTime))music_back.play();
		if (Operate::clock.getElapsedTime() > sf::seconds(5.0f) && Operate::clock.getElapsedTime() < sf::seconds(5.5f))
		{
			BossBullet *bullet1 = new BossBullet();
			(Game::GetGameObjectManager().Add("Bullet1", bullet1));
			bullet1->SetPosition(this->GetSprite().getPosition().x+130 , this->GetSprite().getPosition().y+10 );
		}
		if (Operate::clock.getElapsedTime() > sf::seconds(9.0f) && Operate::clock.getElapsedTime() < sf::seconds(9.5f))
		{
			BossBullet *bullet2 = new BossBullet();
			(Game::GetGameObjectManager().Add("Bullet2", bullet2));
			bullet2->SetPosition(this->GetSprite().getPosition().x + 130, this->GetSprite().getPosition().y + 10);
		}
		if (Operate::clock.getElapsedTime() > sf::seconds(13.0f) && Operate::clock.getElapsedTime() < sf::seconds(13.5f))
		{
			BossBullet *bullet3 = new BossBullet();
			(Game::GetGameObjectManager().Add("Bullet3", bullet3));
			bullet3->SetPosition(this->GetSprite().getPosition().x + 130, this->GetSprite().getPosition().y+10);
		}
		if (Operate::clock.getElapsedTime() > sf::seconds(17.0f) && Operate::clock.getElapsedTime() < sf::seconds(17.5f))
		{
			BossBullet *bullet4 = new BossBullet();
			(Game::GetGameObjectManager().Add("Bullet4", bullet4));
			bullet4->SetPosition(this->GetSprite().getPosition().x + 130, this->GetSprite().getPosition().y + 10);
		}
		if (Operate::clock.getElapsedTime() > sf::seconds(21.0f) && Operate::clock.getElapsedTime() < sf::seconds(21.5f))
		{
			BossBullet *bullet5 = new BossBullet();
			(Game::GetGameObjectManager().Add("Bullet5", bullet5));
			bullet5->SetPosition(this->GetSprite().getPosition().x + 130, this->GetSprite().getPosition().y+10);
		}
		if (Operate::clock.getElapsedTime() > sf::seconds(25.0f) && Operate::clock.getElapsedTime() < sf::seconds(25.5f))
		{
			BossBullet *bullet6 = new BossBullet();
			(Game::GetGameObjectManager().Add("Bullet6", bullet6));
			bullet6->SetPosition(this->GetSprite().getPosition().x + 130, this->GetSprite().getPosition().y + 10);
		}
		music2.pause();
		if (Operate::clock.getElapsedTime() > sf::seconds(12.5f) && Operate::clock.getElapsedTime() < sf::seconds(12.5f) + sf::seconds(elapsedTime))music2.setPlayingOffset(sf::seconds(0));
		    if (Operate::clock.getElapsedTime() > sf::seconds(13.0f) && Operate::clock.getElapsedTime() < sf::seconds(13.5f))
		    {
			if (music2.getStatus() != sf::Music::Status::Playing)music2.play();
			EnemyHealth *health1 = new EnemyHealth();
			EnemyBullet *bullet1 = new EnemyBullet();
			Son *son1 = new Son();
			son1->number = "1";
			son1->SetPosition(this->GetPosition().x+130, this->GetPosition().y);
			bullet1->SetPosition(-50, 700);
			(Game::GetGameObjectManager().Add("Son" + son1->number, son1));
			(Game::GetGameObjectManager().Add("SonBullet" + son1->number, bullet1));
		   	(Game::GetGameObjectManager().Add("SonHealth" + son1->number, health1));
		    }
			if (Operate::clock.getElapsedTime() > sf::seconds(14.5f) && Operate::clock.getElapsedTime() < sf::seconds(14.5f)+sf::seconds(elapsedTime))music2.setPlayingOffset(sf::seconds(0));
			if (Operate::clock.getElapsedTime() > sf::seconds(15.0f) && Operate::clock.getElapsedTime() < sf::seconds(15.5f))
			{
				if (music2.getStatus() != sf::Music::Status::Playing)music2.play();
				EnemyHealth *health2 = new EnemyHealth();
				EnemyBullet *bullet2 = new EnemyBullet();
				Son *son2 = new Son();
				son2->number = "2";
				son2->SetPosition(this->GetPosition().x + 130, this->GetPosition().y);
				bullet2->SetPosition(-50, 700);
				(Game::GetGameObjectManager().Add("Son" + son2->number, son2));
				(Game::GetGameObjectManager().Add("SonBullet" + son2->number, bullet2));
				(Game::GetGameObjectManager().Add("SonHealth" + son2->number, health2));
			}
			if (Operate::clock.getElapsedTime() > sf::seconds(16.5f) && Operate::clock.getElapsedTime() < sf::seconds(16.5f) + sf::seconds(elapsedTime))music2.setPlayingOffset(sf::seconds(0));
			if (Operate::clock.getElapsedTime() > sf::seconds(17.0f) && Operate::clock.getElapsedTime() < sf::seconds(17.5f))
			{
				if (music2.getStatus() != sf::Music::Status::Playing)music2.play();
				EnemyHealth *health3 = new EnemyHealth();
				EnemyBullet *bullet3 = new EnemyBullet();
				Son *son3 = new Son();
				son3->number = "3";
				son3->SetPosition(this->GetPosition().x + 130, this->GetPosition().y);
				bullet3->SetPosition(-50, 700);
				(Game::GetGameObjectManager().Add("Son" + son3->number, son3));
				(Game::GetGameObjectManager().Add("SonBullet" + son3->number, bullet3));
				(Game::GetGameObjectManager().Add("SonHealth" + son3->number, health3));
				
			}
			if (Operate::clock.getElapsedTime() > sf::seconds(18.5f) && Operate::clock.getElapsedTime() < sf::seconds(18.5f) + sf::seconds(elapsedTime))music2.setPlayingOffset(sf::seconds(0));
			if (Operate::clock.getElapsedTime() > sf::seconds(19.0f) && Operate::clock.getElapsedTime() < sf::seconds(19.5f))
			{
				
				if (music2.getStatus() != sf::Music::Status::Playing)music2.play();
				EnemyHealth *health4 = new EnemyHealth();
				EnemyBullet *bullet4 = new EnemyBullet();
				Son *son4 = new Son();
				son4->number = "4";
				son4->SetPosition(this->GetPosition().x + 130, this->GetPosition().y);
				bullet4->SetPosition(-50, 700);
				(Game::GetGameObjectManager().Add("Son" + son4->number, son4));
				(Game::GetGameObjectManager().Add("SonBullet" + son4->number, bullet4));
				(Game::GetGameObjectManager().Add("SonHealth" + son4->number, health4));
			}
			if (Operate::clock.getElapsedTime() > sf::seconds(20.5f) && Operate::clock.getElapsedTime() < sf::seconds(20.5f) + sf::seconds(elapsedTime))music2.setPlayingOffset(sf::seconds(0));
			if (Operate::clock.getElapsedTime() > sf::seconds(21.0f) && Operate::clock.getElapsedTime() < sf::seconds(21.5f))
			{
				if (music2.getStatus() != sf::Music::Status::Playing)music2.play();
				EnemyHealth *health5 = new EnemyHealth();
				EnemyBullet *bullet5 = new EnemyBullet();
				Son *son5 = new Son();
				son5->number = "5";
				son5->SetPosition(this->GetPosition().x + 130, this->GetPosition().y);
				bullet5->SetPosition(-50, 700);
				(Game::GetGameObjectManager().Add("Son" + son5->number, son5));
				(Game::GetGameObjectManager().Add("SonBullet" + son5->number, bullet5));
				(Game::GetGameObjectManager().Add("SonHealth" + son5->number, health5));
			}

		float moveAmount = _velocity * elapsedTime;
		float moveByX = LinearVelocityX(_angle) * moveAmount;
		float moveByY = LinearVelocityY(_angle) * moveAmount;
		if (GetPosition().x + moveByX <= 0 + GetWidth() / 2 - 150
			|| GetPosition().x + GetWidth() / 2 + moveByX >= 800 - 150)
		{
			_angle = 360.0f - _angle;
			if (_angle > 260.0f && _angle < 280.0f)
				_angle += 20.0f;
			if (_angle > 80.0f && _angle < 100.0f)
				_angle += 20.0f;
			moveByX = -moveByX;
		}
		if (GetPosition().y + moveByY <= 0 + GetHeight() / 2 - 60 || GetPosition().y + GetHeight() / 2 + moveByY >= 300 - 30)
		{
			_angle = 180 - _angle;
			moveByY = -moveByY;
		}
		GetSprite().move(moveByX, moveByY);
		if (this->blood <= 0)
		{
			Explosion *explosion6 = new Explosion();
			(Game::GetGameObjectManager().Add("Explosion6", explosion6));
			explosion6->mus.play();
			explosion6->SetPosition(this->GetSprite().getPosition().x - 30, this->GetSprite().getPosition().y - 30);
			(Game::GetGameObjectManager().Remove("BossHealth")); (Game::GetGameObjectManager().Remove("Boss")); //(Game::GetGameObjectManager().Remove("Explosion"));
		}
	}
}
float Boss::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float Boss::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0)
		angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}
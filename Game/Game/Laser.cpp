#include "gamestart.h"
Laser::Laser() :account(3)
{
	music.openFromFile("music/laser.wav");
	Load("image/laser.png");
	assert(IsLoaded());
}
Laser::~Laser()
{

}
void Laser::Update(float elapsedTime)
{
	if (this != NULL)
	{
		
		EnemyPlane1* enemy1 = dynamic_cast<EnemyPlane1*>(Game::GetGameObjectManager().Get("Enemy1" + Game::level));
		EnemyPlane2* enemy2 = dynamic_cast<EnemyPlane2*>(Game::GetGameObjectManager().Get("Enemy2" + Game::level));
		EnemyPlane3* enemy3 = dynamic_cast<EnemyPlane3*>(Game::GetGameObjectManager().Get("Enemy3" + Game::level));
		EnemyPlane4* enemy4 = dynamic_cast<EnemyPlane4*>(Game::GetGameObjectManager().Get("Enemy4" + Game::level));
		EnemyPlane5* enemy5 = dynamic_cast<EnemyPlane5*>(Game::GetGameObjectManager().Get("Enemy5" + Game::level));
		Boss* boss = dynamic_cast<Boss*>(Game::GetGameObjectManager().Get("Boss"));
		Son* son1 = dynamic_cast<Son*>(Game::GetGameObjectManager().Get("Son1"));
		Son* son2 = dynamic_cast<Son*>(Game::GetGameObjectManager().Get("Son2"));
		Son* son3 = dynamic_cast<Son*>(Game::GetGameObjectManager().Get("Son3"));
		Son* son4 = dynamic_cast<Son*>(Game::GetGameObjectManager().Get("Son4"));
		Son* son5 = dynamic_cast<Son*>(Game::GetGameObjectManager().Get("Son5"));
		if (enemy1 != NULL)
		{
			sf::Rect<float>e1BB = enemy1->GetBoundingRect();
			if (e1BB.intersects(GetBoundingRect()))
			{
				enemy1->hittime++;
				if (enemy1->hittime == 50){ enemy1->blood -= 5; enemy1->hittime = 0; }
			}
		}
		if (enemy2 != NULL)
		{
			sf::Rect<float>e2BB = enemy2->GetBoundingRect();
			if (e2BB.intersects(GetBoundingRect()))
			{
				enemy2->hittime++;
				if (enemy2->hittime == 50){ enemy2->blood -= 5; enemy2->hittime = 0; }
			}
		}
		if (enemy3 != NULL)
		{
			sf::Rect<float>e3BB = enemy3->GetBoundingRect();
			if (e3BB.intersects(GetBoundingRect()))
			{
				enemy3->hittime++;
				if (enemy3->hittime == 50){ enemy3->blood -= 5; enemy3->hittime = 0; }
			}
		}
		if (enemy4 != NULL)
		{
			sf::Rect<float>e4BB = enemy4->GetBoundingRect();
			if (e4BB.intersects(GetBoundingRect()))
			{
				enemy4->hittime++;
				if (enemy4->hittime == 50){ enemy4->blood -= 5; enemy4->hittime = 0; }
			}

		}
		if (enemy5 != NULL)
		{
			sf::Rect<float>e5BB = enemy5->GetBoundingRect();
			if (e5BB.intersects(GetBoundingRect()))
			{
				enemy5->hittime++;
				if (enemy5->hittime == 50){ enemy5->blood -= 5; enemy5->hittime = 0; }
			}

		}
		if (boss != NULL)
		{
			sf::Rect<float>ebBB = boss->GetBoundingRect();
			if (ebBB.intersects(GetBoundingRect()))
			{
				boss->hittime++;
				if (boss->hittime == 50){ boss->blood -= 5; boss->hittime = 0; }
			}

		}
		if (son1 != NULL)
		{
			sf::Rect<float>es1BB = son1->GetBoundingRect();
			if (es1BB.intersects(GetBoundingRect()))
			{
				son1->hittime++;
				if (son1->hittime >= 50){ son1->blood -= 10; son1->hittime = 0; }
			}

		}
		if (son2 != NULL)
		{
			sf::Rect<float>es2BB = son2->GetBoundingRect();
			if (es2BB.intersects(GetBoundingRect()))
			{
				son2->hittime++;
				if (son2->hittime >= 50){ son2->blood -= 10; son2->hittime = 0; }
			}

		}
		if (son3 != NULL)
		{
			sf::Rect<float>es3BB = son3->GetBoundingRect();
			if (es3BB.intersects(GetBoundingRect()))
			{
				son3->hittime++;
				if (son3->hittime >= 50){ son3->blood -= 10; son3->hittime = 0; }
			}

		}
		if (son4 != NULL)
		{
			sf::Rect<float>es4BB = son4->GetBoundingRect();
			if (es4BB.intersects(GetBoundingRect()))
			{
				son4->hittime++;
				if (son4->hittime >= 50){ son4->blood -= 10; son4->hittime = 0; }
			}

		}
		if (son5 != NULL)
		{
			sf::Rect<float>es5BB = son5->GetBoundingRect();
			if (es5BB.intersects(GetBoundingRect()))
			{
				son5->hittime++;
				if (son5->hittime >= 50){ son5->blood -= 10; son5->hittime = 0; }
			}

		}
	}
}
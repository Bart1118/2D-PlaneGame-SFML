#include "gamestart.h"
EnemyBullet::EnemyBullet() 
{
	Load("image/enemybullet.png");
	assert(IsLoaded());
}
EnemyBullet::~EnemyBullet()
{

}
void EnemyBullet::Update(float elapsedTime)
{
	PlayerPlane* player = dynamic_cast<PlayerPlane*>(Game::GetGameObjectManager().Get("Player"));
	if (player != NULL)
	{
		sf::Rect<float>e0BB = player->GetBoundingRect();
		if (e0BB.intersects(GetBoundingRect()))
		{
			Boom *boom = new Boom();
			(Game::GetGameObjectManager().Add("Boom", boom));
			boom->SetPosition(player->GetSprite().getPosition().x - 47, player->GetSprite().getPosition().y-70);
			player->hit++;
			if (player->hit >= 90){ player->med-=0.5; player->hit = 0; (Game::GetGameObjectManager().Remove("Boom")); }
		}

	}
}
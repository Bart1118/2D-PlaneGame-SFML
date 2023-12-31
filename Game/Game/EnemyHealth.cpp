#include "gamestart.h"
EnemyHealth::EnemyHealth()
{
	rect.setSize(sf::Vector2f(80, 13));
	rect.setFillColor(sf::Color::Red);
	Load(rect);
	assert(IsLoaded());
}
EnemyHealth::~EnemyHealth()
{

}
void EnemyHealth::Update(float elapsedTime)
{

}
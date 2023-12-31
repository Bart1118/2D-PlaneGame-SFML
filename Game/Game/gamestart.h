#pragma once
#include "stdafx.h"
#include "Bullet.h"
#include "Laser.h"
#include "PlayerPlane.h"
#include "PlayerHealth.h"
#include "PlayerStars.h"
#include "EnemyPlane1.h"
#include "EnemyPlane2.h"
#include "EnemyPlane3.h"
#include "EnemyPlane4.h"
#include "EnemyPlane5.h"
#include "Boss.h"
#include "BossBullet.h"
#include "Son.h"
#include "Boom.h"
#include "Explosion.h"
#include "EnemyBullet.h"
#include "EnemyHealth.h"
#include "GameObjectManager.h"
#include "Operate.h"
class Game
{
public: 
	static void start();
	static sf::RenderWindow& GetWindow();
	static std::string level;
	static int LEVEL;
	const static sf::Event& GetInput();
	static GameObjectManager& GetGameObjectManager();
	enum GameState{ Uninitialized, ShowingSplash, Paused, ShowingMenu, ChoosingMenu, Playing, Exiting };//用枚举类型来代替常量表示游戏状态
	static GameState gamestate;
	enum Operatestate{ Keyboarding, Mousing,Nothing};
	static Operatestate operatestate;
private:
	static bool isExiting();
	static void GameLoop();
	static sf::RenderWindow mainWindow;
	static void ShowSplashScreen();
	static void ShowMenu();
	static void ChooseOperate();
	static GameObjectManager _gameObjectManager;
	//static PlayerCar _player1;
};

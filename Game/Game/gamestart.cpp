#include "gamestart.h"
#include "MainMenu.h"
#include "Operate.h"
#include "SplashScreen.h"
Game::GameState Game::gamestate = Game::GameState::ShowingSplash;
Game::Operatestate Game::operatestate = Game::Operatestate::Nothing;
int Game::LEVEL = 0;
std::string Game::level = "_0";
sf::RenderWindow Game::mainWindow;
sf::Clock Operate::clock;
GameObjectManager Game::_gameObjectManager;
sf::Font font;
sf::Text text;
sf::Texture t1;
sf::Sprite s1;
sf::Texture t2;
sf::Sprite s2;
sf::Texture t3;
sf::Sprite s3;
sf::Music music1;
sf::Music music2;
sf::Music music3;
sf::Music music4;
sf::Music music5;
sf::Music music6;
void Game::start()
{
	mainWindow.create(sf::VideoMode(800, 600,32), "PLANE GAME");
	mainWindow.setFramerateLimit(6000);
	t1.loadFromFile("image/back1.png");
	s1.setTexture(t1);
	t2.loadFromFile("image/back2.png");
	s2.setTexture(t2);
	t3.loadFromFile("image/back3.png");
	s3.setTexture(t3);
	//LEVEL 1
	Game::LEVEL = 1;
	Game::level = "_1";
	_gameObjectManager.RemoveAll();
	mainWindow.clear(sf::Color(255, 255, 255));
	Bullet *bullet_1 = new Bullet();
	bullet_1->SetPosition(-50, -50);
	Laser *laser_1 = new Laser();
	laser_1->SetPosition(0, -700);
	PlayerPlane *player_1 = new PlayerPlane();
	player_1->SetPosition(350, 400);
	PlayerHealth *health_1 = new PlayerHealth();
	health_1->SetPosition(10, 550);
	PlayerStars *stars_1 = new PlayerStars();
	stars_1->SetPosition(170, 550);
	_gameObjectManager.Add("bullet", bullet_1);
	_gameObjectManager.Add("laser", laser_1);
	_gameObjectManager.Add("Player", player_1);
	_gameObjectManager.Add("PlayerHealth", health_1);
	_gameObjectManager.Add("PlayerStars", stars_1);
	Boom* boom1 = dynamic_cast<Boom*>(Game::GetGameObjectManager().Get("Boom"));
	EnemyBullet *enemybullet1_1 = new EnemyBullet();
	enemybullet1_1->SetPosition(-50, 700);
	EnemyBullet *enemybullet2_1 = new EnemyBullet();
	enemybullet2_1->SetPosition(-50, -50);
	EnemyBullet *enemybullet3_1 = new EnemyBullet();
	enemybullet3_1->SetPosition(-50, 700);
	EnemyPlane1 *enemy1_1 = new EnemyPlane1();
	enemy1_1->SetPosition(200, 200);
	EnemyPlane2 *enemy2_1 = new EnemyPlane2();
	enemy2_1->SetPosition(300, 200);
	EnemyPlane3 *enemy3_1 = new EnemyPlane3();
	enemy3_1->SetPosition(400, 200);
	EnemyHealth* enemyhealth1_1 = new EnemyHealth();
	EnemyHealth* enemyhealth2_1 = new EnemyHealth();
	EnemyHealth* enemyhealth3_1 = new EnemyHealth();
	_gameObjectManager.Add("enemybullet1_1", enemybullet1_1);
	_gameObjectManager.Add("enemybullet2_1", enemybullet2_1);
	_gameObjectManager.Add("enemybullet3_1", enemybullet3_1);
	_gameObjectManager.Add("Enemy1_1", enemy1_1);
	_gameObjectManager.Add("Enemy2_1", enemy2_1);
	_gameObjectManager.Add("Enemy3_1", enemy3_1);
	_gameObjectManager.Add("EnemyHealth1_1", enemyhealth1_1);
	_gameObjectManager.Add("EnemyHealth2_1", enemyhealth2_1);
	_gameObjectManager.Add("EnemyHealth3_1", enemyhealth3_1);
	while ((_gameObjectManager.GetObejectCount() > 8 && boom1 != NULL) || (_gameObjectManager.GetObejectCount() > 9 && boom1 == NULL)){  GameLoop(); }
	//LEVEL 2
	Game::LEVEL = 2;
	Game::level = "_2";
	Operate::clock.restart();
	_gameObjectManager.RemoveAll();
	mainWindow.clear(sf::Color(255, 255, 255));
	while (Operate::clock.getElapsedTime().asSeconds() <= 3.0f)
	{

		font.loadFromFile("arial.ttf");
		text.setFont(font); text.setString("LEVEL ClEAR!" );
		text.setFillColor(sf::Color::Red);
		text.setCharacterSize(60);
		text.setPosition(200, 70);
		mainWindow.clear(sf::Color(255, 255, 255));
		mainWindow.draw(text);
		mainWindow.display();
	}
	Operate::clock.restart();
	Bullet *bullet_2 = new Bullet();
	bullet_2->SetPosition(-50, -50);
	Laser *laser_2 = new Laser();
	laser_2->SetPosition(0, -700);
	PlayerPlane *player_2 = new PlayerPlane();
	player_2->SetPosition(350, 400);
	PlayerHealth *health_2 = new PlayerHealth();
	health_2->SetPosition(10, 550);
	PlayerStars *stars_2 = new PlayerStars();
	stars_2->SetPosition(170, 550);
	_gameObjectManager.Add("bullet", bullet_2);
	_gameObjectManager.Add("laser", laser_2);
	_gameObjectManager.Add("Player", player_2);
	_gameObjectManager.Add("PlayerHealth", health_2);
	_gameObjectManager.Add("PlayerStars", stars_2);
	Boom* boom2 = dynamic_cast<Boom*>(Game::GetGameObjectManager().Get("Boom"));
	EnemyBullet *enemybullet1_2 = new EnemyBullet();
	enemybullet1_2->SetPosition(-50, 700);
	EnemyBullet *enemybullet2_2 = new EnemyBullet();
	enemybullet2_2->SetPosition(-50, -50);
	EnemyBullet *enemybullet3_2 = new EnemyBullet();
	enemybullet3_2->SetPosition(-50, 700);
	EnemyBullet *enemybullet4_2 = new EnemyBullet();
	enemybullet4_2->SetPosition(-50, -50);
	EnemyBullet *enemybullet5_2 = new EnemyBullet();
	enemybullet5_2->SetPosition(-50, 700);
	EnemyPlane1 *enemy1_2 = new EnemyPlane1();
	enemy1_2->SetPosition(200, 200);
	EnemyPlane2 *enemy2_2 = new EnemyPlane2();
	enemy2_2->SetPosition(300, 200);
	EnemyPlane3 *enemy3_2 = new EnemyPlane3();
	enemy3_2->SetPosition(400, 200);
	EnemyPlane4 *enemy4_2 = new EnemyPlane4();
	enemy4_2->SetPosition(500, 200);
	EnemyPlane5 *enemy5_2 = new EnemyPlane5();
	enemy5_2->SetPosition(600, 200);
	EnemyHealth* enemyhealth1_2 = new EnemyHealth();
	EnemyHealth* enemyhealth2_2 = new EnemyHealth();
	EnemyHealth* enemyhealth3_2 = new EnemyHealth();
	EnemyHealth* enemyhealth4_2 = new EnemyHealth();
	EnemyHealth* enemyhealth5_2 = new EnemyHealth();
	_gameObjectManager.Add("enemybullet1_2", enemybullet1_2);
	_gameObjectManager.Add("enemybullet2_2", enemybullet2_2);
	_gameObjectManager.Add("enemybullet3_2", enemybullet3_2);
	_gameObjectManager.Add("enemybullet4_2", enemybullet4_2);
	_gameObjectManager.Add("enemybullet5_2", enemybullet5_2);
	_gameObjectManager.Add("Enemy1_2", enemy1_2);
	_gameObjectManager.Add("Enemy2_2", enemy2_2);
	_gameObjectManager.Add("Enemy3_2", enemy3_2);
	_gameObjectManager.Add("Enemy4_2", enemy4_2);
	_gameObjectManager.Add("Enemy5_2", enemy5_2);
	_gameObjectManager.Add("EnemyHealth1_2", enemyhealth1_2);
	_gameObjectManager.Add("EnemyHealth2_2", enemyhealth2_2);
	_gameObjectManager.Add("EnemyHealth3_2", enemyhealth3_2);
	_gameObjectManager.Add("EnemyHealth4_2", enemyhealth4_2);
	_gameObjectManager.Add("EnemyHealth5_2", enemyhealth5_2);

	while ((_gameObjectManager.GetObejectCount() > 10 && boom2 != NULL) || (_gameObjectManager.GetObejectCount() > 11 && boom2 == NULL)){  GameLoop(); }
	////LEVEL 3
	(Game::GetGameObjectManager().Remove("Explosion1"));
	(Game::GetGameObjectManager().Remove("Explosion2"));
	(Game::GetGameObjectManager().Remove("Explosion3"));
	(Game::GetGameObjectManager().Remove("Explosion4"));
	(Game::GetGameObjectManager().Remove("Explosion5"));
	Game::LEVEL = 3;
	Game::level = "_3";
	Operate::clock.restart();
	_gameObjectManager.RemoveAll();
	//_gameObjectManager.Remove("Explosion1");
	//_gameObjectManager.Remove("Explosion2");
	//_gameObjectManager.Remove("Explosion3");
	mainWindow.clear(sf::Color(255, 255, 255));
	while (Operate::clock.getElapsedTime().asSeconds() <= 3.0f)
	{

		font.loadFromFile("arial.ttf");
		text.setFont(font); text.setString("WARNING!\nBOSS DETECTED");
		text.setFillColor(sf::Color::Red);
		text.setCharacterSize(60);
		text.setPosition(200, 70);
		mainWindow.clear(sf::Color(255, 255, 255));
		mainWindow.draw(text);
		mainWindow.display();
	}
	Operate::clock.restart();
	Bullet *bullet_3 = new Bullet();
	bullet_3->SetPosition(-50, -50);
	Laser *laser_3 = new Laser();
	laser_3->SetPosition(0, -700);
	PlayerPlane *player_3 = new PlayerPlane();
	player_3->SetPosition(350, 400);
	PlayerHealth *health_3 = new PlayerHealth();
	health_3->SetPosition(10, 550);
	PlayerStars *stars_3 = new PlayerStars();
	stars_3->SetPosition(170, 550);
	_gameObjectManager.Add("bullet", bullet_3);
	_gameObjectManager.Add("laser", laser_3);
	_gameObjectManager.Add("Player", player_3);
	_gameObjectManager.Add("PlayerHealth", health_3);
	_gameObjectManager.Add("PlayerStars", stars_3);
	Boom* boom3 = dynamic_cast<Boom*>(Game::GetGameObjectManager().Get("Boom"));
	Boss *boss = new Boss();
	boss->SetPosition(250, 200);
	EnemyHealth* bosshealth = new EnemyHealth();
	_gameObjectManager.Add("Boss", boss);
	_gameObjectManager.Add("BossHealth", bosshealth);
	while (boss->blood > 0)
{ GameLoop(); if (boss->blood <= 0) 
	{
		_gameObjectManager.RemoveAll();
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			font.loadFromFile("arial.ttf");
			text.setFont(font); text.setString("YOU WIN!\n\n\n\n\n\n   Press ESC to exit");
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(60);
			text.setPosition(250, 70);
			mainWindow.clear(sf::Color(255, 255, 255));
			mainWindow.draw(text);
			mainWindow.display();
		}
	} 
}
	start();
}
sf::RenderWindow& Game::GetWindow()
{
	return mainWindow;
}
const sf::Event& Game::GetInput()
{
	sf::Event currentEvent;
	mainWindow.pollEvent(currentEvent);
	return currentEvent;
}
bool Game::isExiting()
{
	if (gamestate == Game::Exiting)
		return true;
	else
		return false;
}
void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(mainWindow);
	gamestate = Game::ShowingMenu;
}
void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(mainWindow);
	switch (result)
	{
	case MainMenu::Play:gamestate = ChoosingMenu;
		music4.openFromFile("music/confirm.wav");
		music4.play();
		break;
	case MainMenu::Exit:gamestate = Exiting;
		music4.openFromFile("music/confirm.wav");
		music4.play();
		break;
	case MainMenu::Nothing:music3.openFromFile("music/error.wav");
		music3.play();
	}
}
void Game::ChooseOperate()
{
	Operate operate;
	Operate::OperateMethod result = operate.Choose(mainWindow);
	sf::Vector2i vector2i(350, 400);
	switch (result)
	{
	case Operate::Keyboard:operatestate = Keyboarding;
		gamestate = Playing;
		music4.openFromFile("music/go.wav");
		music4.play();
		music1.openFromFile("music/ready.wav");
		music1.play();
		break;
	case Operate::Mouse:operatestate = Mousing;
		gamestate = Playing;
		music4.openFromFile("music/go.wav");
		music4.play();
		music1.openFromFile("music/ready.wav");
		music1.play();
		sf::Mouse::setPosition(vector2i, mainWindow);
		break;	
	case Operate::No:music3.openFromFile("music/error.wav");
		music3.play();
		break;
	}
}
GameObjectManager& Game::GetGameObjectManager()
{
	return Game::_gameObjectManager;
}
void Game::GameLoop()
{
	sf::Event currentEvent;
	//从消息队列里面拿出消息
	mainWindow.pollEvent(currentEvent);
	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Regular);
	text.setFillColor(sf::Color::Green);
	text.setString("LEVEL" + Game::level);
	text.setPosition(630,550);
	switch (gamestate)
 {
	case Game::ShowingSplash:
	{
		ShowSplashScreen();
		if (sf::Event::MouseButtonPressed)ShowMenu();
		break;
	}
	case Game::ShowingMenu:
	{
		ShowMenu();
		break;
	}
	case Game::ChoosingMenu:
	{
		ChooseOperate();
		break;
	}
	case Game::Playing:
	{
		//用白色填充游戏画面
		mainWindow.clear(sf::Color(255, 255, 255));
		if (Game::LEVEL == 1)mainWindow.draw(s1);
		if (Game::LEVEL == 2)mainWindow.draw(s2);
		if (Game::LEVEL == 3)mainWindow.draw(s3);
		mainWindow.draw(text);
		if (_gameObjectManager.GetObejectCount() != 0)
		{
			PlayerPlane* player1 = dynamic_cast<PlayerPlane*>(Game::GetGameObjectManager().Get("Player"));
			if (player1->med <= 0)_gameObjectManager.RemoveAll();
				_gameObjectManager.UpdateAll();
				_gameObjectManager.DrawAll(mainWindow);
		}
		mainWindow.display();
		if (_gameObjectManager.GetObejectCount() == 0)
		{
			sf::Texture tex; tex.loadFromFile("image/defeated.png"); sf::Sprite sp(tex);
			music2.openFromFile("music/clock.wav");
			music2.play();
			while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ mainWindow.clear(); mainWindow.draw(sp); mainWindow.display(); }  gamestate = ShowingMenu; Game::start();
		}
		if (currentEvent.type == sf::Event::Closed)
		{
			gamestate = Game::Exiting;
		}
		if (currentEvent.type == sf::Event::KeyPressed)
		{
			if (currentEvent.key.code == sf::Keyboard::Escape) { gamestate = ShowingMenu;   Game::start(); }
		}
		break;
	}
	case Game::Exiting:
	{
		mainWindow.close();
	}
 }
}
int main()
{
	Game::start();
	return 0;
}
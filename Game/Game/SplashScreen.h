#pragma once
#include "stdafx.h"
class SplashScreen
{
public:
	SplashScreen();
	void Show(sf::RenderWindow &window);
	sf::Music music;
	sf::Font font;
	sf::Text text;
};
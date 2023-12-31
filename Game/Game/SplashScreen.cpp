#include "SplashScreen.h"
#include "gamestart.h"
SplashScreen::SplashScreen()
{
	music.openFromFile("music/splashmusic.wav");
	font.loadFromFile("chinese.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString(L"µÿ«Ú±£Œ¿’Ω");
	text.setCharacterSize(60);
	text.setPosition(250, 100);
}
void SplashScreen::Show(sf::RenderWindow &window)
{
	music.play();
	sf::Texture image;
	if (image.loadFromFile("image/splashscreen.png") != true)
	{
		return;
	}
	sf::Sprite sprite(image);
	window.clear();
	window.draw(sprite);
	window.draw(text);
	window.display();
	sf::Event event;
	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}
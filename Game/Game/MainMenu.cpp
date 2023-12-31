#include "MainMenu.h"
#include "gamestart.h"
MainMenu::MenuResult MainMenu::Show(sf::RenderWindow &window)
{
	sf::Texture image;
	image.loadFromFile("image/menu.png");
	sf::Sprite sprite(image);
	sf::Texture playbuttonimage;
	playbuttonimage.loadFromFile("image/start.png");
	sf::Sprite Playbutton(playbuttonimage);
	Playbutton.setPosition(250, 100);
	sf::Texture exitbuttonimage;
	exitbuttonimage.loadFromFile("image/exit.png");
	sf::Sprite Exitbutton(exitbuttonimage);
	Exitbutton.setPosition(300, 300);
	//�����������������Χ
	MenuItem playbutton;//play�ĵ����Χ
	playbutton.rect.top = 100;
	playbutton.rect.left = 250;
	playbutton.rect.width = 223;
	playbutton.rect.height = 550;
	playbutton.action = Play;
	MenuItem exitbutton;//exit�ĵ����Χ
	exitbutton.rect.top = 300;
	exitbutton.rect.left = 300;
	exitbutton.rect.width = 380;
	exitbutton.rect.height = 500;
	exitbutton.action = Exit;
	//�ѵ����Χ�Ž���������
	menuitems.push_back(playbutton);
	menuitems.push_back(exitbutton);
	window.clear();
	window.draw(sprite);
	window.draw(Playbutton);
	window.draw(Exitbutton);
	window.display();
	return GetMenuResponse(window);
}
//�ж������λ���Ƿ��ھ�����������Ӷ�����״̬����
MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	for (it = menuitems.begin(); it != menuitems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.width > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.height > x)
		{
			return (*it).action;
		}
	}
	return Nothing;
}
// ������궯����������Ӧ����Ӧ
MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
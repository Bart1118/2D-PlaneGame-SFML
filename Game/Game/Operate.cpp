#include "Operate.h"
#include "gamestart.h"
Operate::OperateMethod Operate::Choose(sf::RenderWindow &window)
{
	sf::Font font;
	font.loadFromFile("chinese.ttf");
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setString("Please Choose Your Play Mode:");
	text.setPosition(200,20);
	sf::Text text1;
	text1.setFont(font);
	text1.setFillColor(sf::Color::White);
	text1.setString("Keyboard(hardcore)");
	text1.setPosition(80, 150);
	sf::Text text11;
	text11.setFont(font);
	text11.setFillColor(sf::Color::White);
	text11.setString(L"��������Ʒɻ�\n���ո����ӵ�\n��Ctrl���伤��");
	text11.setPosition(130, 480);
	sf::Text text2;
	text2.setFont(font);
	text2.setFillColor(sf::Color::White);
	text2.setString("Mouse(Easycore)");
	text2.setPosition(470, 150);
	sf::Text text22;
	text22.setFont(font);
	text22.setFillColor(sf::Color::White);
	text22.setString(L"����ƶ����Ʒɻ�\n�����������ӵ�\n����Ҽ����伤��");
	text22.setPosition(490, 480);
	sf::Texture image;
	//image.loadFromFile("image/.png");
	sf::Sprite sprite(image);
	sf::Texture mousebuttonimage;
	mousebuttonimage.loadFromFile("image/mouse.png");
	sf::Texture keyboardbuttonimage;
	keyboardbuttonimage.loadFromFile("image/keyboard.png");
	sf::Sprite Mousebutton(mousebuttonimage);
	sf::Sprite Keyboardbutton(keyboardbuttonimage);
	Mousebutton.setPosition(500, 200);
	Keyboardbutton.setPosition(70,250);
	//�����������������Χ
	Operation mousebutton;//play�ĵ����Χ
	mousebutton.rect.top = 200;
	mousebutton.rect.left = 500;
	mousebutton.rect.width = 474;
	mousebutton.rect.height = 701;
	mousebutton.action = Mouse;
	Operation keyboardbutton;//exit�ĵ����Χ
	keyboardbutton.rect.top = 250;
	keyboardbutton.rect.left = 70;
	keyboardbutton.rect.height = 380;
	keyboardbutton.rect.width = 370;
	keyboardbutton.action = Keyboard;
	//�ѵ����Χ�Ž���������
	operations.push_back(mousebutton);
	operations.push_back(keyboardbutton);
	window.clear();
	window.draw(text);
	window.draw(text1);
	window.draw(text11);
	window.draw(text22);
	window.draw(text2);
	window.draw(sprite);
	window.draw(Mousebutton);
	window.draw(Keyboardbutton);
	window.display();
	return GetMenuResponse(window);
}
//�ж������λ���Ƿ��ھ�����������Ӷ�����״̬����
Operate::OperateMethod Operate::HandleClick(int x, int y)
{
	std::list<Operation>::iterator it;
	for (it = operations.begin(); it != operations.end(); it++)
	{
		sf::Rect<int> OperationRect = (*it).rect;
		if (OperationRect.width > y
			&& OperationRect.top < y
			&& OperationRect.left < x
			&& OperationRect.height > x)
		{
			return (*it).action;
		}
	};
	return No;
}
// ������궯����������Ӧ����Ӧ
Operate::OperateMethod  Operate::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				clock.restart();
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
		}
	}
}
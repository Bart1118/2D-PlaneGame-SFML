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
	text11.setString(L"方向键控制飞机\n按空格发射子弹\n左Ctrl发射激光");
	text11.setPosition(130, 480);
	sf::Text text2;
	text2.setFont(font);
	text2.setFillColor(sf::Color::White);
	text2.setString("Mouse(Easycore)");
	text2.setPosition(470, 150);
	sf::Text text22;
	text22.setFont(font);
	text22.setFillColor(sf::Color::White);
	text22.setString(L"鼠标移动控制飞机\n鼠标左键发射子弹\n鼠标右键发射激光");
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
	//设置鼠标点击矩形区域范围
	Operation mousebutton;//play的点击范围
	mousebutton.rect.top = 200;
	mousebutton.rect.left = 500;
	mousebutton.rect.width = 474;
	mousebutton.rect.height = 701;
	mousebutton.action = Mouse;
	Operation keyboardbutton;//exit的点击范围
	keyboardbutton.rect.top = 250;
	keyboardbutton.rect.left = 70;
	keyboardbutton.rect.height = 380;
	keyboardbutton.rect.width = 370;
	keyboardbutton.action = Keyboard;
	//把点击范围放进容器里面
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
//判断鼠标点击位置是否在矩形区域里面从而返回状态参数
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
// 根据鼠标动作来做出相应的响应
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
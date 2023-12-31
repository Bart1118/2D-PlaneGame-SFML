#pragma once
#include "stdafx.h"
#include <list>
class Operate
{
public:
	enum OperateMethod{ Mouse,Keyboard,No };
	struct Operation
	{
	public:
		sf::Rect<int> rect;
		OperateMethod action;
	};
	OperateMethod Choose(sf::RenderWindow &window);
	static sf::Clock clock;
private:
	OperateMethod GetMenuResponse(sf::RenderWindow &window);
	OperateMethod HandleClick(int x, int y);
	std::list<Operation> operations;
};
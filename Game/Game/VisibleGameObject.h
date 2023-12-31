#pragma once
#include "stdafx.h"
class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();
	virtual void Load(std::string filename);
	virtual void Load(sf::RectangleShape rect);
	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float elapsedTime);
	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition()const;
	virtual bool IsLoaded()const;
	sf::Sprite& GetSprite();
	sf::RectangleShape& GetRect();
	virtual float GetWidth()const;
	virtual float GetHeight()const;
	virtual sf::Rect<float>GetBoundingRect()const;
protected:
	sf::Sprite _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;
	sf::RectangleShape _rect;
};
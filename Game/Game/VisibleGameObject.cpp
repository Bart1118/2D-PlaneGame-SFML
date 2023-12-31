#include "VisibleGameObject.h"
VisibleGameObject::VisibleGameObject() :_isLoaded(false)
{
	
}
VisibleGameObject::~VisibleGameObject()
{

}
void VisibleGameObject::Load(std::string filename)
{
	if (_image.loadFromFile(filename) == false)
	{
		_filename = "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image,true);
		_isLoaded = true;
	}
}
void VisibleGameObject::Load(sf::RectangleShape rect)
{
	_rect = rect;
	_isLoaded = true;
}
void VisibleGameObject::Draw(sf::RenderWindow &window)
{
	if (_isLoaded)
	{
		window.draw(_sprite);
		window.draw(_rect);
	}
}
void VisibleGameObject::Update(float elapsedTime)
{

}
void VisibleGameObject::SetPosition(float x, float y)
{
	if (_isLoaded)
	{
		_sprite.setPosition(x, y);
		_rect.setPosition(x, y);
	}
}
sf::Vector2f VisibleGameObject::GetPosition()const
{
	if (_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}
sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}
sf::RectangleShape& VisibleGameObject::GetRect()
{
	return _rect;
}
bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}
float VisibleGameObject::GetWidth()const
{
	return _sprite.getLocalBounds().width;
}
float VisibleGameObject::GetHeight()const
{
	return _sprite.getLocalBounds().height;
}
sf::Rect<float> VisibleGameObject::GetBoundingRect()const
{
	return _sprite.getGlobalBounds();
}
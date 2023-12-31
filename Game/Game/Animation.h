#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"
class Animation :public VisibleGameObject//, public sf::Transformable
{
public:
	Animation();
	Animation(sf::Time dt);
	virtual ~Animation();
	virtual void Load(std::string _filename, std::size_t numframes);
	virtual void setFramesize(sf::Vector2i framesize);
	virtual void Update(float elapsedTime);
	bool mRepeat;
	sf::Time mDuration;
protected:
	sf::Vector2i mFrameSize;
	std::size_t mNumFrames;
	std::size_t mCurrentFrame;
	sf::Time mElapsedTime;
	
};
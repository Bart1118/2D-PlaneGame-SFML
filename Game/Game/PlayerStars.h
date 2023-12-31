#pragma once
#include "VisibleGameObject.h"
class PlayerStars :
	public VisibleGameObject
{
public:
	PlayerStars();
	virtual ~PlayerStars();
	void Update(float elapsedTime);
};
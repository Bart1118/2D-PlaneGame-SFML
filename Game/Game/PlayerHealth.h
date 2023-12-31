#pragma once
#include "VisibleGameObject.h"
class PlayerHealth :
	public VisibleGameObject
{
public:
	PlayerHealth();
	virtual ~PlayerHealth();
	void Update(float elapsedTime);
};
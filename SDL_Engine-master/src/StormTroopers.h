#pragma once
#ifndef __STORMTROOPERS__
#define __STORMTROOPERS__

#include "Sprite.h"
class StormTroopers :
    public Sprite
{

public:
	StormTroopers();
	~StormTroopers();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

private:
	
	
};

#endif /* defined (__STORMTROOPERS__) */
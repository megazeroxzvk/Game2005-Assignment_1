#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Background.h"
#include "Scene.h"
#include "Plane.h"
#include "Player.h"
#include "Button.h"
#include "Ship.h"
#include "Wookie.h"
#include "Label.h"
#include "ThermalDetonator.h"
#include "StormTroopers.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
private:
	// IMGUI Function
	void GUI_Function() const;
	std::string m_guiTitle;
	
	glm::vec2 m_mousePosition;

	// Sprites
	Wookie* m_pWookie;
	ThermalDetonator* m_pThermalDetonator;
	StormTroopers* m_pStormTroopers;
	//Plane* m_pPlaneSprite;
	//Player* m_pPlayer;
	//Ship* m_pShip;
	//bool m_playerFacingRight;

	// UI Items
	Button* m_pThrowButton;
	Button* m_pResetButton;
	Label* m_pInstructionsLabel;

	//Labels for showing current information-
	Label* m_pStormTroopersLocation;
	Label* m_pAngle;
	Label* m_pSpeed;
	Label* m_pRange;
	Label* m_pTimeRequired;

	// Background
	Background* m_pBackground;
};

#endif /* defined (__PLAY_SCENE__) */
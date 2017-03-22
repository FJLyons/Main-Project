#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

#include "Variables_Global.h"

#include "Manager_Input.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void						Init();
	virtual int						    Update();
	virtual void						Draw(sf::RenderWindow &window);
	virtual void						Input(sf::Event Event);

	virtual bool						IsRunning();

protected:
	GlobalVariables*					GV = GlobalVariables::GetInstance();
	InputManager*						inputManager = InputManager::GetInstance();
	//AudioManager*						_audioManager = AudioManager::GetInstance();

	bool								_running;
	unsigned int						_lastTime; //time of last update;

	GameScenes							_swapScene;
};


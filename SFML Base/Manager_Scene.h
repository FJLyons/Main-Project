#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// C++ Headers
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

// Custom Classes
#include "Variables_Global.h"

#include "Scene.h"
#include "Scene_Splash.h"
#include "Scene_Main_Menu.h"
#include "Scene_Game.h"
#include "Scene_Load.h"
#include "Scene_Options.h"
#include "Scene_Instructions.h"


class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init();
	void Process();
	void Input(sf::Event evt);
	void SwapScene();

private:
	std::vector<Scene*>	m_currentScene;
	int	m_runningScene;
	int	m_previousScene;		
	bool m_running;
};


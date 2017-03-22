#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

#include "Variables_Const.h"
#include "Variables_Enum.h"

class GlobalVariables
{
public:
	static GlobalVariables * GetInstance();
private:
	static GlobalVariables * globalVariablesInstance;

public:
	GlobalVariables();
	~GlobalVariables();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);

	int getCurrentScene();
	void setCurrentScene(int current);

	sf::RenderWindow* windowReference;

private:
	int currentScene;

public:
	sf::Color Grey = sf::Color(125, 125, 125, 255);
	sf::Color DarkGreen = sf::Color(0, 125, 0, 255);


public:
	std::map<ActionState, std::string> stateNames;
	void createStateNames();
};
#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

class GlobalVariables
{
public:
	static GlobalVariables * getInstance();
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

	enum GameStates { 
		CONTINUE, 
		GAME, 
		LOAD, 
		OPTIONS, 
		INSTRUCTIONS, 
		PAUSE, 
		GAMEOVER, 
		MAINMENU, 
		SPLASH 
	};

	sf::Vector2f screenSize = sf::Vector2f(1920, 1080);
	sf::Vector2f screenSizeHalf = sf::Vector2f(screenSize.x / 2, screenSize.y / 2);
	sf::RenderWindow* windowReference;

private:
	int currentScene;

public:
	sf::Color Grey = sf::Color(125, 125, 125, 255);
	sf::Color DarkGreen = sf::Color(0, 125, 0, 255);


public:
	enum GOAPState {
		Search_for_Castle,
		Castle_Sighted,
		Castle_in_Range,
		Castle_Dead,
		Attack_Castle
	};

	std::map<GOAPState, std::string> stateNames;
	void createStateNames();
};
#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

#include "Variables_Global.h"
#include "Manager_Input.h"

#define MENU_INDEX 5

class MainMenu
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	MainMenu();
	~MainMenu();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);
	void input(sf::Event Event);

private:
	sf::Vector2f screenSize = GV->screenSize;

	void swapScreen();

	void moveUp();
	void moveDown();

	int getPressedItem();

	// Art
	sf::Texture logoTexture;
	sf::Sprite logoSprite;
	sf::Vector2f scaleFactor; // Resolution vs Screen

	// Index
	int selectedItemIndex;

	// Font
	sf::Font font;
	sf::Text text[MENU_INDEX];

	enum MenuOptions {
		GAME,
		LOAD,
		OPTIONS,
		INSTRUCTIONS,
		QUIT
	};

};


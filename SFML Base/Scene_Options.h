#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

#include "Variables_Global.h"
#include "Manager_Input.h"

#define MENU_INDEX 2

class OptionsMenu
{
private:
	GlobalVariables* myGlobalOptions = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	OptionsMenu();
	~OptionsMenu();

	void init();
	void update();
	void draw(sf::RenderWindow &window);
	void input(sf::Event Event);

private:
	sf::Vector2f screenSize = myGlobalOptions->screenSize;

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
		OPTION1,
		OPTION2
	};
};

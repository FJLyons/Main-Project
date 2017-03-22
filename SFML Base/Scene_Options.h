#pragma once

#include "Scene.h"

#define MENU_INDEX 2

class OptionsMenu : public Scene
{
public:
	OptionsMenu();
	~OptionsMenu();

	void Init() override;
	int Update() override;
	void Draw(sf::RenderWindow &window) override;
	void Input(sf::Event Event) override;
	bool IsRunning() override;

private:
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


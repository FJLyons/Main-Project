#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Variables_Global.h"

class Map
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();

public:
	Map();
	~Map();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);

private:
	sf::Vector2f screenSize = GV->screenSize;
	sf::Vector2f screenSizeHalf = GV->screenSizeHalf;

	sf::RectangleShape m_rectangleShape;

};


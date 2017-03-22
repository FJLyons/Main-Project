#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Variables_Global.h"

class Map
{
private:
	GlobalVariables* GV = GlobalVariables::GetInstance();

public:
	Map();
	~Map();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);

private:
	sf::RectangleShape m_rectangleShape;
};


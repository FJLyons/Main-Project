#include "Map.h"



Map::Map()
{
	Init();
}


Map::~Map()
{
}

void Map::Init()
{
	m_rectangleShape = sf::RectangleShape();
	m_rectangleShape.setSize(screenSize);
	m_rectangleShape.setOrigin(screenSizeHalf);
	m_rectangleShape.setPosition(screenSizeHalf);
	m_rectangleShape.setFillColor(GV->DarkGreen);
	m_rectangleShape.setOutlineColor(sf::Color::Red);
	m_rectangleShape.setOutlineThickness(2.0f);
}

void Map::Update()
{

}

void Map::Draw(sf::RenderWindow &window)
{
	window.draw(m_rectangleShape);
}

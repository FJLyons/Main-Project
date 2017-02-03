#include "Structure.h"



Structure::Structure()
{
	Init();
}


Structure::~Structure()
{
}

void Structure::Init()
{
	m_rectangleShape = sf::RectangleShape();
	m_rectangleShape.setSize(m_size);
	m_rectangleShape.setOrigin(m_sizeHalf);
	m_rectangleShape.setPosition(screenSizeHalf);
	m_rectangleShape.setFillColor(GV->Grey);
	m_rectangleShape.setOutlineColor(sf::Color::Red);
	m_rectangleShape.setOutlineThickness(2.0f);
}

void Structure::Update()
{

}

void Structure::Draw(sf::RenderWindow &window)
{
	window.draw(m_rectangleShape);
}

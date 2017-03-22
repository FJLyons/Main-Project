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
	m_size = sf::Vector2f(125, 125);
	m_sizeHalf = sf::Vector2f(m_size.x / 2, m_size.y / 2);
	m_position = SCREEN_SIZE_HALF;

	m_rectangleShape = sf::RectangleShape();
	m_rectangleShape.setSize(m_size);
	m_rectangleShape.setOrigin(m_sizeHalf);
	m_rectangleShape.setPosition(m_position);
	m_rectangleShape.setFillColor(GlobalVariables::GetInstance()->Grey);
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

#include "Unit.h"



Unit::Unit()
{
	Init();
}


Unit::~Unit()
{
}

void Unit::Init()
{
	m_radius = 20;
	m_circleShape = sf::CircleShape();
	m_circleShape.setRadius(m_radius);
	m_circleShape.setOrigin(sf::Vector2f(m_radius / 2, m_radius / 2));
	m_circleShape.setPosition(sf::Vector2f(100, 540));
	m_circleShape.setFillColor(sf::Color::Yellow);
	m_circleShape.setOutlineColor(sf::Color::Red);
	m_circleShape.setOutlineThickness(m_radius / 10.0f);
}

void Unit::Update()
{

}

void Unit::Draw(sf::RenderWindow &window)
{
	window.draw(m_circleShape);
}

#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Variables_Global.h"

class Structure
{
public:
	Structure();
	~Structure();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);

private:
	float m_value_defense;
	float m_range_sight;

	float m_value_resource;
	float m_value_build;
	float m_value_sell;

	// Spiked Wall
	float m_value_attack;
	float m_speed_attack;
	float m_range_attack;

public:
	sf::RectangleShape m_rectangleShape; 
	sf::Vector2f m_size;
	sf::Vector2f m_sizeHalf;
	sf::Vector2f m_position;
};


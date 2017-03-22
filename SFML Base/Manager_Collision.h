#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include<vector>

#include "Unit.h"
#include "Structure.h"



class CollisionManager
{
public:
	static CollisionManager * GetInstance();
private:
	static CollisionManager * collisionManagerInstance;

public:
	CollisionManager();
	~CollisionManager();

//private:
	Structure* left_castle;
	Structure* right_castle;

public:
	bool CheckUnitPOVCastle(sf::CircleShape*, bool rightCastle);
	bool CheckUnitCastle(sf::CircleShape* , bool rightCastle);

	sf::Vector2f MoveToCastle(sf::Vector2f, bool rightCastle);
	sf::Vector2f Normalise(sf::Vector2f v1);
};


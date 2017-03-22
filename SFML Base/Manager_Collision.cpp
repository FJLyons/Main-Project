#include "Manager_Collision.h"

CollisionManager* CollisionManager::collisionManagerInstance = nullptr;

CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

CollisionManager * CollisionManager::GetInstance()
{
	if (collisionManagerInstance == nullptr)
	{
		collisionManagerInstance = new CollisionManager();
	}
	return collisionManagerInstance;
}

bool CollisionManager::CheckUnitPOVCastle(sf::CircleShape* unit, bool rightCastle)
{
	//Simplest circle test
	//Distance between points <= sum of radius

	float radius1 = unit->getRadius();
	float radius2 = (right_castle->m_size.x + right_castle->m_size.y) / 4;

	float xd, yd;
	if (rightCastle)
	{
		xd = unit->getPosition().x - right_castle->m_position.x;
		yd = unit->getPosition().y - right_castle->m_position.y;
	}
	else
	{
		xd = unit->getPosition().x - left_castle->m_position.x;
		yd = unit->getPosition().y - left_castle->m_position.y;
	}

	return sqrt(xd * xd + yd * yd) <= radius1 + radius2;;
}

bool CollisionManager::CheckUnitCastle(sf::CircleShape* unit, bool rightCastle)
{
	//Simplest circle test
	//Distance between points <= sum of radius

	float radius1 = unit->getRadius();
	float radius2 = (right_castle->m_size.x + right_castle->m_size.y) / 4;

	float xd, yd;
	if (rightCastle)
	{
		xd = unit->getPosition().x - right_castle->m_position.x;
		yd = unit->getPosition().y - right_castle->m_position.y;
	}
	else
	{
		xd = unit->getPosition().x - left_castle->m_position.x;
		yd = unit->getPosition().y - left_castle->m_position.y;
	}

	return sqrt(xd * xd + yd * yd) <= radius1 + radius2;;
}

sf::Vector2f CollisionManager::MoveToCastle(sf::Vector2f position, bool rightCastle)
{
	if (rightCastle)
	{
		return Normalise(sf::Vector2f(right_castle->m_position - position));
	}
	else
	{
		return Normalise(sf::Vector2f(left_castle->m_position - position));
	}
}

sf::Vector2f CollisionManager::Normalise(sf::Vector2f vec) 
{
	float length(sqrt((vec.x * vec.x) + (vec.y * vec.y)));

	if (length != 0)
	{
		sf::Vector2f normalised((vec.x / length), (vec.y / length));
		return normalised;
	}

	return sf::Vector2f(0, 0);
}

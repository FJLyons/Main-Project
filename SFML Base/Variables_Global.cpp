#include "Variables_Global.h"

GlobalVariables* GlobalVariables::globalVariablesInstance = nullptr;


GlobalVariables::GlobalVariables()
{
	Init();
}


GlobalVariables::~GlobalVariables()
{
}

GlobalVariables * GlobalVariables::getInstance()
{
	if (globalVariablesInstance == nullptr)
	{
		globalVariablesInstance = new GlobalVariables();
	}
	return globalVariablesInstance;
}


void GlobalVariables::Init()
{
	currentScene = GameStates::SPLASH;
	createStateNames();
}

void GlobalVariables::Update()
{

}

void GlobalVariables::Draw(sf::RenderWindow &window)
{

}

int GlobalVariables::getCurrentScene(){ return currentScene; }
void GlobalVariables::setCurrentScene(int current){ currentScene = current; }

void GlobalVariables::createStateNames()
{
	stateNames[Search_for_Castle] = "Search for Castle";
	stateNames[Castle_Sighted] = "Castle Sighted";
	stateNames[Castle_in_Range] = "Castle in Range";
	stateNames[Castle_Dead] = "Castle Dead";
	stateNames[Attack_Castle] = "Attack Castle";
}
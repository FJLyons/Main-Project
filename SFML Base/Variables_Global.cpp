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
}

void GlobalVariables::Update()
{

}

void GlobalVariables::Draw(sf::RenderWindow &window)
{

}

int GlobalVariables::getCurrentScene(){ return currentScene; }
void GlobalVariables::setCurrentScene(int current){ currentScene = current; }

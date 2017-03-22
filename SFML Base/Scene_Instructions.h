#pragma once

#include "Scene.h"

class InstructionsScreen : public Scene
{
public:
	InstructionsScreen();
	~InstructionsScreen(); 
	
	void Init() override;
	int Update() override;
	void Draw(sf::RenderWindow &window) override;
	void Input(sf::Event Event) override;
	bool IsRunning() override;

private:
	sf::Font font;
	sf::Text text;
};


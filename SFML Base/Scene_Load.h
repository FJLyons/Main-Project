#pragma once

#include "Scene.h"

class LoadScreen : public Scene
{
public:
	LoadScreen();
	~LoadScreen();

	void Init() override;
	int Update() override;
	void Draw(sf::RenderWindow &window) override;
	void Input(sf::Event Event) override;
	bool IsRunning() override;


private:
	sf::Font font;
	sf::Text text;
};


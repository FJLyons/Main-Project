#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <conio.h>
#include <windows.h>

#include "Variables_Global.h"
#include "Manager_Input.h"

#define FULL_COLOUR 255

class SplashScreen
{
private:
	GlobalVariables* GV = GlobalVariables::getInstance();
	InputManager* inputManager = InputManager::getInstance();

public:
	SplashScreen();
	~SplashScreen();

	void Init();
	void Update();
	void Draw(sf::RenderWindow &window);
	void input(sf::Event Event);	

private:
	sf::Vector2f screenSize = GV->screenSize;

	void print(const std::string &str, int delay_time);
	void fade();

	// Art
	sf::Texture logoTexture;
	sf::Sprite logoSprite;

	// Font
	sf::Font font;
	sf::Text pressAnyText;

	// Art Variables
	int logoAlphaFade; // Fade Image Alpha
	float logoFadeMultiply; // Increase fade speed
	sf::Vector2f scaleFactor; // Resolution vs Screen

	// Print text
	sf::Clock clock; // System Clock for timing print
	std::string pressAnyString; // On Screen Text - Press Any Key
	int currentLetter; // Current letter being printed
	bool printed; // Has been printed to screen

	// Fade text
	int textAlphaFade; // alpha Fade for text
	bool fading; // is the text fading
};


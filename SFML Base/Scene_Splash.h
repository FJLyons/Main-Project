#pragma once

#include "Scene.h"

class SplashScreen : public Scene
{
public:
	SplashScreen();
	~SplashScreen();

	void Init() override;
	int Update() override;
	void Draw(sf::RenderWindow &window) override;
	void Input(sf::Event Event) override;
	bool IsRunning() override;

private:
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


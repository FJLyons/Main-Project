#include "Scene_Splash.h"


SplashScreen::SplashScreen()
{
	Init();
}


SplashScreen::~SplashScreen()
{
}

void SplashScreen::Init()
{
	// Art
	scaleFactor = sf::Vector2f(1, 1);

	if (!logoTexture.loadFromFile("content\\art\\other\\logo.png")){ std::cout << "Logo Art Error" << std::endl; }
	logoTexture.setSmooth(true);
	logoSprite.setTexture(logoTexture);
	// logoSprite.setScale(scaleFactor);
	logoSprite.setOrigin(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	logoSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	logoSprite.setColor(sf::Color(255, 255, 255, 0));

	logoAlphaFade = 0;
	logoFadeMultiply = 1.0f;

	// Writing
	pressAnyString = "Press Any Button to Continue!";
	currentLetter = 0;

	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	pressAnyText.setFont(font);
	pressAnyText.setString("");
	// pressAnyText.setScale(scaleFactor);
	// pressAnyText.setOrigin(0.5f, 0.5f); // Did not noticably move text, still needed to be divided by 2 later
	pressAnyText.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	pressAnyText.setCharacterSize(18);

	printed = false;
	textAlphaFade = 255;
	fading = false;

	_swapScene = GameScenes::SPLASH;
}

int SplashScreen::Update()
{
	fade(); // Fade in image


	return (int)_swapScene;
}

void SplashScreen::Draw(sf::RenderWindow &window)
{
	window.draw(logoSprite);
	window.draw(pressAnyText);
}

void SplashScreen::Input(sf::Event Event)
{
	if (Event.type == sf::Event::KeyPressed)
	{
		std::cout << Event.key.code << std::endl;
		_swapScene = GameScenes::MAINMENU;
	}
}

bool SplashScreen::IsRunning()
{
	return _running;
}

void SplashScreen::print(const std::string& str, int delay) 
{
	// Start printing
	if (clock.getElapsedTime().asMilliseconds() > delay && currentLetter < str.size())
	{
		clock.restart();
		currentLetter++;
		pressAnyText.setString(sf::String(str.substr(0, currentLetter)));
		pressAnyText.setPosition((SCREEN_WIDTH / 2) - pressAnyText.getLocalBounds().width / 2.0f,
								(SCREEN_HEIGHT / 2) - pressAnyText.getLocalBounds().height / 2.0f);
	}

	// Finished
	if (currentLetter >= str.size())
	{
		printed = true;
		fading = true;
	}
}

void SplashScreen::fade()
{
	if (logoAlphaFade < FULL_COLOUR)
	{
		logoSprite.setColor(sf::Color(FULL_COLOUR, FULL_COLOUR, FULL_COLOUR, logoAlphaFade));
		logoAlphaFade += logoFadeMultiply;
		logoFadeMultiply *= 1.007f; // 1.98333 seconds - License to kill
	}

	// Check if string has finished printing
	if (printed == false) 
	{ 
		print(pressAnyString, 100); 
	}

	// If string has printed, change its alpha
	if (printed == true)
	{
		pressAnyText.setColor(sf::Color(FULL_COLOUR, FULL_COLOUR, FULL_COLOUR, textAlphaFade)); // Set Alpha for string

		// Decrease alpha - fade out
		if (fading == true && textAlphaFade >= 50) 
		{ 
			textAlphaFade -= 3; 
		}
		else 
		{ 
			fading = false; 
		}

		// Increase alpha - fade in
		if (fading == false && textAlphaFade <= FULL_COLOUR - 5) 
		{ 
			textAlphaFade += 5; 
		}
		else 
		{ 
			fading = true; 
		}
	}
}

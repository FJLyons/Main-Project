#include "Scene_Options.h"

OptionsMenu::OptionsMenu()
{
	Init();
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::Init()
{
	//Art
	scaleFactor = sf::Vector2f((1280.0f / 1920.0f), (720.0f / 1080.0f));

	if (!logoTexture.loadFromFile("content\\art\\other\\logo.png")){ std::cout << "Logo Art Error" << std::endl; }
	logoTexture.setSmooth(true);
	logoSprite.setTexture(logoTexture);
	logoSprite.setScale(scaleFactor);
	logoSprite.setOrigin(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	logoSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

	// Index
	selectedItemIndex = 0;

	//Text
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");

	text[0].setString("test");

	for (int i = 0; i < MENU_INDEX; i++)
	{
		text[i].setString("test");
		text[i].setFont(font);
		text[i].setPosition((SCREEN_WIDTH / 2) - text[i].getLocalBounds().width / 3.5f, (SCREEN_HEIGHT / 2) + (48.0f * i) - text[i].getLocalBounds().height / 2.0f);
		text[i].setCharacterSize(18);
		text[i].setColor(sf::Color::White);
	}

	text[0].setColor(sf::Color::Red);

	_swapScene = GameScenes::OPTIONS;
}

int OptionsMenu::Update()
{

	return (int)_swapScene;
}

void OptionsMenu::Input(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		_swapScene = GameScenes::MAINMENU;
	}

	if (inputManager->KeyPressed(sf::Keyboard::Return))
	{
		// swapScreen(); // Toggle option
	}

	if (inputManager->KeyPressed(sf::Keyboard::Up))
	{
		std::cout << "Up" << std::endl;
		moveUp();
	}

	if (inputManager->KeyPressed(sf::Keyboard::Down))
	{
		std::cout << "Down" << std::endl;
		moveDown();
	}
}

bool OptionsMenu::IsRunning()
{
	return _running;
}

void OptionsMenu::Draw(sf::RenderWindow &window)
{
	window.draw(logoSprite);

	for (int i = 0; i < MENU_INDEX; i++)
	{
		window.draw(text[i]);
	}
}

void OptionsMenu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
	// Jump to bottom
	else
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex = MENU_INDEX - 1;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void OptionsMenu::moveDown()
{
	if (selectedItemIndex + 1 < MENU_INDEX)
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
	// Jump to top
	else
	{
		text[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex = 0;
		text[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int OptionsMenu::getPressedItem()
{
	return selectedItemIndex;
}


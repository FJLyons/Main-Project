#include "Scene_Main_Menu.h"


MainMenu::MainMenu()
{
	Init();
}


MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
	//Art
	scaleFactor = sf::Vector2f(1, 1);

	if (!logoTexture.loadFromFile("content\\art\\other\\logo.png")){ std::cout << "Logo Art Error" << std::endl; }
	logoTexture.setSmooth(true);
	logoSprite.setTexture(logoTexture);
	logoSprite.setScale(scaleFactor);
	logoSprite.setOrigin(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));
	logoSprite.setPosition(sf::Vector2f(screenSize.x / 2, screenSize.y / 2));

	// Index
	selectedItemIndex = 0;

	//Text
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	
	text[0].setString("New Game");
	text[1].setString("Load Game");
	text[2].setString("Options");
	text[3].setString("Instructions");
	text[4].setString("Quit");

	for (int i = 0; i < MENU_INDEX; i++)
	{
		text[i].setFont(font);
		text[i].setPosition((screenSize.x / 2) - text[i].getLocalBounds().width / 3.5f, (screenSize.y / 2) + (48.0f * i) - text[i].getLocalBounds().height / 2.0f);
		text[i].setCharacterSize(18);
		text[i].setColor(sf::Color::White);
	}

	text[0].setColor(sf::Color::Red);
}

void MainMenu::Update()
{

}

void MainMenu::Draw(sf::RenderWindow &window)
{
	window.draw(logoSprite);

	for (int i = 0; i < MENU_INDEX; i++)
	{
		window.draw(text[i]);
	}
}

void MainMenu::input(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::BackSpace)) 
	{ 
		std::cout << "Back Space" << std::endl;
		GV->setCurrentScene(GV->SPLASH);
	}

	if (inputManager->KeyPressed(sf::Keyboard::Return))
	{
		swapScreen();
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

void MainMenu::swapScreen()
{
	if (getPressedItem() == GAME) 
	{
		GV->setCurrentScene(GV->GAME);
		std::cout << "New Game" << std::endl;
	}

	else if (getPressedItem() == LOAD) 
	{
		GV->setCurrentScene(GV->LOAD);
		std::cout << "Load Game" << std::endl;
	}

	else if (getPressedItem() == OPTIONS) 
	{
		GV->setCurrentScene(GV->OPTIONS);
		std::cout << "Options Menu" << std::endl;
	}

	else if (getPressedItem() == INSTRUCTIONS) 
	{
		GV->setCurrentScene(GV->INSTRUCTIONS);
		std::cout << "Instrctions Screen" << std::endl;
	}

	if (getPressedItem() == QUIT)
	{
		std::cout << "Quit" << std::endl;
		GV->windowReference->close();
	}
}

void MainMenu::moveUp()
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

void MainMenu::moveDown()
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

int MainMenu::getPressedItem()
{
	// Index in menu
	return selectedItemIndex;
}

// SFML Headers 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib")
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

// Open GL
#include "SFML/OpenGL.hpp"

// FMOD Headers
//#pragma comment(lib,"fmodex_vc.lib")
//#include "fmod.hpp"
//#include "fmod_errors.h"

// C++ Headers
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

// Custom Classes
#include "SceneManager.h"
#include "GlobalVariables.h"
#include "InputManager.h"

SceneManager *sceneManager;
GlobalVariables* myGlobalOptions;

///Entrypoint of application 
int main()
{
	// Random Seed
	srand(time(0));

	// Get Global Variables
	sceneManager = new SceneManager();
	myGlobalOptions = GlobalVariables::getInstance();

	// Create the main window 
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	sf::Vector2f screenSize = myGlobalOptions->screenSize;
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "GAME", sf::Style::Default, settings);

	myGlobalOptions->windowReference = &window;

	// Set Frame Rate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	// Classes

	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			InputManager::getInstance()->update(Event);

			// Close Window
			if (Event.type == Event.Closed) { window.close(); }
			if (Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape) { window.close(); }

			// Update input
			if (myGlobalOptions->getCurrentScene() == myGlobalOptions->SPLASH) { sceneManager->splashScreen->input(Event); }
			else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->MAINMENU) { sceneManager->mainMenu->input(Event); }
			else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->GAME) { sceneManager->game->input(Event); }
			else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->LOAD) { sceneManager->load->input(Event); }
			else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->OPTIONS) { sceneManager->optionsMenu->input(Event); }
			else if (myGlobalOptions->getCurrentScene() == myGlobalOptions->INSTRUCTIONS) { sceneManager->instructions->input(Event); }
			else
				sceneManager->input(window, Event);
		}

		//prepare frame
		window.clear();

		// Update and Draw
		sceneManager->update();
		sceneManager->draw(window);

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}

//// Load a font
//sf::Font font;
//font.loadFromFile("C:\\Windows\\Fonts\\Arial.TTF");
//
//// Create a formatted text string
//sf::Text text;
//text.setFont(font);
//text.setString("Hello World");
//text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
//text.setPosition(0, 0);
//text.setCharacterSize(18);
//
//// Create a circle
//sf::CircleShape circle(32);
//circle.setPosition(100, 100);
//
//// Setup FMOD
//FMOD::System* FMODsys; //will point to the FMOD system
//FMOD_RESULT result;
//result = FMOD::System_Create(&FMODsys);         // Create the main system object.
//if (result != FMOD_OK) { cout << "FMOD error!" << result << FMOD_ErrorString(result); }
//
//result = FMODsys->init(100, FMOD_INIT_NORMAL, 0);   // Initialize FMOD.
//if (result != FMOD_OK) { cout << "FMOD error!" << result << FMOD_ErrorString(result); }
//
//// Loading a sound
//FMOD::Sound *sound;
//result = FMODsys->createSound("../media/wave.mp3", FMOD_DEFAULT, 0, &sound);
//if (result != FMOD_OK) { cout << "FMOD error! (%d) %s\n" << result; }
//
//// Playing a sound
//FMOD::Channel *channel;
//FMODsys->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);

////draw frame items
//window.draw(text);
//window.draw(circle);
//
//// Update FMOD
//FMODsys->update();

// Resolution?
//view.setCenter(512, 384);
//sf::Vector2u size = window.getSize();
//view.setSize(768 * size.x / size.y, 768);
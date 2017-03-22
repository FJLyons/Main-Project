#include "Manager_Scene.h"

SceneManager::SceneManager()
{
	Init();
}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
	SplashScreen* splash = new SplashScreen();
	m_currentScene.push_back(splash);
	m_runningScene = 0;
}

void SceneManager::Process()
{
	if (m_currentScene.back()->IsRunning())
	{
		m_previousScene = m_runningScene;

		m_runningScene = m_currentScene.back()->Update();
		m_currentScene.back()->Draw(*GlobalVariables::GetInstance()->windowReference);

		SwapScene();
	}
}

void SceneManager::Input(sf::Event evt)
{
	m_currentScene.back()->Input(evt);
}

void SceneManager::SwapScene()
{
	if (m_runningScene != m_previousScene)
	{
		delete m_currentScene.back();
		m_currentScene.pop_back();

		if (m_runningScene == GameScenes::SPLASH)
		{
			SplashScreen* splash = new SplashScreen();
			m_currentScene.push_back(splash);
		}

		else if (m_runningScene == GameScenes::MAINMENU)
		{
			MainMenu* menu = new MainMenu();
			m_currentScene.push_back(menu);
		}

		else if (m_runningScene == GameScenes::GAME)
		{
			Game* game = new Game();
			m_currentScene.push_back(game);
		}

		else if (m_runningScene == GameScenes::LOAD)
		{
			LoadScreen* load = new LoadScreen();
			m_currentScene.push_back(load);
		}

		else if (m_runningScene == GameScenes::OPTIONS)
		{
			OptionsMenu* options = new OptionsMenu();
			m_currentScene.push_back(options);
		}

		else if (m_runningScene == GameScenes::INSTRUCTIONS)
		{
			InstructionsScreen* instructions = new InstructionsScreen();
			m_currentScene.push_back(instructions);
		}
	}
}

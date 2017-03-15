#include "Scene_Game.h"

Game::Game()
{
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	text.setFont(font);
	text.setString("Main Game");
	text.setPosition(screenSize.x / 2, screenSize.y / 2);
	text.setCharacterSize(18);

	InitGOAP();
	InitMCTS();
}

Game::~Game()
{
}

void Game::InitGOAP()
{
	goap_goal_win = new GOAPWorldState();
	goap_goal_win->SetVariable(GV->Castle_Dead, true);
	goap_goal_win->SetVariable(GV->Search_for_Castle, true);
	goap_goal_win->m_priority = 100;

	goap_initial_state = new GOAPWorldState();
	goap_initial_state->SetVariable(GV->Search_for_Castle, true);
	goap_initial_state->SetVariable(GV->Castle_Sighted, false);
	goap_initial_state->SetVariable(GV->Castle_in_Range, false);
	goap_initial_state->SetVariable(GV->Attack_Castle, false);
	goap_initial_state->SetVariable(GV->Castle_Dead, false);

	AStarSearch = new GOAPPlanner();
	try
	{
		std::vector<GOAPAction> the_plan = AStarSearch->Plan(*goap_initial_state, *goap_goal_win, *leftAgent->actions);
		std::cout << "GOAP Path = \n";

		for (std::vector<GOAPAction>::reverse_iterator rit = the_plan.rbegin(); rit != the_plan.rend(); ++rit)
		{
			std::cout << rit->GetName() << std::endl;
		}
		std::cout << "\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Sorry, could not find a path!\n";
	}
}

void Game::InitMCTS()
{
	mcts_initial_state = new MCTSWorldState();

	UCTSearch = new MCTSPlanner();

	MCTSAction next_action;
	std::cout << "MCTS Path = \n";

	try
	{
		while (next_action.action != GV->ActionState::Castle_Dead)
		{
			next_action = UCTSearch->Plan(*mcts_initial_state);

			mcts_initial_state->ApplyAction(next_action);

			mcts_initial_state = new MCTSWorldState(next_action);

			// mcts_initial_state = next_action.next_state;

			std::cout << next_action.GetName() << std::endl;
		}
		std::cout << "\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Sorry, could not find a path!\n";
	}
}

void Game::Update()
{
	int i = 0;
}

void Game::Draw(sf::RenderWindow &window)
{
	map->Draw(window);
	castle->Draw(window);
	leftAgent->Draw(window);
}

void Game::input(sf::Event Event)
{
	if (Event.type == sf::Event::KeyPressed)
	{ 
		std::cout << Event.key.code << std::endl; 
	}

	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		GV->setCurrentScene(GV->MAINMENU);
	}

	controller(Event);
}

void Game::controller(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}



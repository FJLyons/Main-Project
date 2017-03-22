#include "Scene_Game.h"

Game::Game()
{
	Init();
}

Game::~Game()
{
}

void Game::Init()
{
	font.loadFromFile("content\\fonts\\kenvector_future.TTF");
	text.setFont(font);
	text.setString("Main Game");
	text.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	text.setCharacterSize(18);

	clock.restart();

	CollisionManager::GetInstance()->right_castle = castle;
	CollisionManager::GetInstance()->left_castle = castle;

	InitGOAP();
	InitMCTS();

	_swapScene = GameScenes::GAME;
}

void Game::InitGOAP()
{
	goap_goal_win = new GOAPWorldState();
	goap_goal_win->SetVariable(ActionState::Castle_Dead, true);
	goap_goal_win->SetVariable(ActionState::Search_for_Castle, true);
	goap_goal_win->m_priority = 100;

	goap_initial_state = new GOAPWorldState();
	goap_initial_state->SetVariable(ActionState::Search_for_Castle, true);
	goap_initial_state->SetVariable(ActionState::Castle_Sighted, false);
	goap_initial_state->SetVariable(ActionState::Castle_in_Range, false);
	goap_initial_state->SetVariable(ActionState::Attack_Castle, false);
	goap_initial_state->SetVariable(ActionState::Castle_Dead, false);

	AStarSearch = new GOAPPlanner();

	GOAP();
}

void Game::InitMCTS()
{
	mcts_initial_state = new MCTSWorldState();

	UCTSearch = new MCTSPlanner();

	next_action = MCTSAction();

	std::cout << "MCTS Path = \n";

	MCTS();
}

int Game::Update()
{
	sf::Time elapsed = clock.restart();

	if (GOAP_Plan.size() > 0)
	{
		int action = leftAgent->Update(GOAP_Plan.back().GetAction(), elapsed.asMilliseconds());
		
		if (action == SUCCESS)
		{

			std::cout << GOAP_Plan.back().GetName() << "- Success" << std::endl;

			GOAP_Plan.pop_back();

			if (GOAP_Plan.size() == 0)
			{
				bool replan = true;
			}
		}

		else if (action == FAIL)
		{
			// fail
			int i = 0;
		}
	}

	if (next_action.action != ActionState::Castle_Dead)
	{
		int action = rightAgent->Update(next_action.action, elapsed.asMilliseconds());

		if (action == SUCCESS)
		{
			std::cout << next_action.GetName() << "- Success" << std::endl;

			MCTS();

			if (next_action.action == ActionState::Castle_Dead)
			{
				bool replan = true;
			}
		}

		else if (action == FAIL)
		{
			// fail
			int i = 0;
		}
	}

	return (int)_swapScene;
}

void Game::Draw(sf::RenderWindow &window)
{
	map->Draw(window);
	castle->Draw(window);
	leftAgent->Draw(window);
	rightAgent->Draw(window);
}

void Game::Input(sf::Event Event)
{
	if (Event.type == sf::Event::KeyPressed)
	{ 
		std::cout << Event.key.code << std::endl; 
	}

	if (inputManager->KeyPressed(sf::Keyboard::BackSpace))
	{
		std::cout << "Back Space" << std::endl;
		_swapScene = GameScenes::MAINMENU;
	}

	controller(Event);
}

bool Game::IsRunning()
{
	return _running;
}

void Game::controller(sf::Event Event)
{
	if (inputManager->KeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}

void Game::GOAP()
{
	try
	{
		GOAP_Plan = AStarSearch->Plan(*goap_initial_state, *goap_goal_win, *leftAgent->actions);
		std::cout << "GOAP Path = \n";

		for (std::vector<GOAPAction>::reverse_iterator rit = GOAP_Plan.rbegin(); rit != GOAP_Plan.rend(); ++rit)
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

void Game::MCTS()
{
	try
	{
		//while (next_action.action != ActionState::Castle_Dead)
		//{
			next_action = UCTSearch->Plan(*mcts_initial_state);

			mcts_initial_state->ApplyAction(next_action);

			mcts_initial_state = new MCTSWorldState(next_action); // mcts_initial_state = next_action.next_state;

			std::cout << next_action.GetName() << std::endl;
		//}
		std::cout << "\n";
	}
	catch (const std::exception&)
	{
		std::cout << "Sorry, could not find a path!\n";
	}
}



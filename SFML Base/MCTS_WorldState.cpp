#include "MCTS_WorldState.h"
#include "Variables_Global.h"


MCTSWorldState::MCTSWorldState() :
	m_isTerminal(false),
	m_winner(0)
{
	for (int i = 0; i < GlobalVariables::ActionState::ENUMSIZE - 1; i++)
	{
		m_moves.push_back(GlobalVariables::ActionState(i));
	}
}


MCTSWorldState::~MCTSWorldState()
{
	reset();
}

MCTSWorldState::MCTSWorldState(const MCTSWorldState & other) :
	m_isTerminal(other.m_isTerminal),
	m_winner(other.m_winner),
	m_moves(other.m_moves)
{
}

MCTSWorldState & MCTSWorldState::operator=(const MCTSWorldState & other)
{
	this->m_winner = other.m_winner;
	this->m_isTerminal = other.m_isTerminal;
	this->m_moves = other.m_moves;
	return *this;
}

bool MCTSWorldState::IsTerminal() const
{
	return m_isTerminal;
}

void MCTSWorldState::ApplyAction(const MCTSAction & action)
{
	// sanity check
	if (action.action < 0 || action.action > m_moves.size())
	{
		return;
	}

	// End states?

	// Test
	//for (int i = 0; i < 5; i++)
	//{
	//	if (m_moves[i] == m_moves[GlobalVariables::ActionState::Castle_Dead])
	//	{
	//		int debug = 0;
	//	}
	//}

	for (int i = 0; i < GlobalVariables::ActionState::ENUMSIZE - 1; i++)
	{
		// if winning combo found,
		if (m_moves[i] < -1 &&
			action.action == GlobalVariables::ActionState::Castle_Dead)
		{
			m_winner = m_moves[i];
			m_isTerminal = true;
			return;
		}
	}

	//// if no winning combo found
	//// find number of empty tiles
	//int num_empty = 0;

	//for (int i = 0; i < GlobalVariables::ActionState::ENUMSIZE - 1; i++)
	//{
	//	if (m_moves[i] == -1)
	//	{
	//		num_empty++;
	//	}
	//}

	//if (num_empty == 0)
	//{
	//	m_winner = -1;
	//	m_isTerminal = true;
	//}
}

void MCTSWorldState::GetActions(std::vector<MCTSAction>& actions) const
{
	actions.clear();

	for (int i = 0; i < GlobalVariables::ActionState::ENUMSIZE - 1; i++)
	{
		actions.push_back(GlobalVariables::ActionState(i));
	}
}

bool MCTSWorldState::GetRandomAction(MCTSAction & action) const
{
	std::vector<MCTSAction> actions;
	GetActions(actions);

	// sanity check
	if (actions.empty())
	{
		return false;
	}

	action = actions[floor(std::rand() % actions.size())]; // Random shuffle
	return true;
}

const float MCTSWorldState::Evaluate() const
{
	return 1; // if good move
	return 0; // if bad move
	return 0.5f; // if draw
}

void MCTSWorldState::reset()
{
	m_isTerminal = false;
	m_winner = 0;
}

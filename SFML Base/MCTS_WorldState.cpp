#include "MCTS_WorldState.h"
#include "Variables_Global.h"


MCTSWorldState::MCTSWorldState() :
	m_isTerminal(false),
	m_winner(0),
	m_previousAction(MCTSAction())
{
	// Add available actions
	for (int i = 0; i < m_previousAction.m_children.size(); i++)
	{
		m_moves.push_back(m_previousAction.m_children[i]);
	}
}

MCTSWorldState::MCTSWorldState(MCTSAction action) :
	m_isTerminal(false),
	m_winner(0),
	m_previousAction(action)
{
	// Add available actions
	for (int i = 0; i < m_previousAction.m_children.size(); i++)
	{
		m_moves.push_back(m_previousAction.m_children[i]);
	}
}


MCTSWorldState::~MCTSWorldState()
{
	reset();
}

MCTSWorldState::MCTSWorldState(const MCTSWorldState & other) :
	m_isTerminal(other.m_isTerminal),
	m_winner(other.m_winner),
	m_moves(other.m_moves),
	m_previousAction(other.m_previousAction)
{
}

MCTSWorldState & MCTSWorldState::operator=(const MCTSWorldState & other)
{
	this->m_winner = other.m_winner;
	this->m_isTerminal = other.m_isTerminal;
	this->m_moves = other.m_moves;
	this->m_previousAction = other.m_previousAction;
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

	// List available moves
	if (m_moves.size() < action.m_children.size())
	{
		m_moves = action.m_children;
		//for (int k = action.m_children.size() - m_moves.size(); k < action.m_children.size(); k++)
		//{
		//	m_moves.push_back(action.m_children[k]);
		//}
	}

	for (int i = 0; i < m_moves.size(); i++)
	{
		for (int j = 0; j < action.m_children.size(); j++)
		{
			// if winning combo found,
			if (m_moves[i] == action.m_children[j])
			{
				if (action.m_winner[j] == true)
				{
					m_winner = m_moves[i];
					m_isTerminal = true;
					return;
				}
			}
		}
	}
}

void MCTSWorldState::GetActions(std::vector<MCTSAction>& actions) const
{
	actions.clear();

	for (int i = 0; i < m_moves.size(); i++)
	{
		actions.push_back(m_moves[i]);
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

const float MCTSWorldState::Evaluate(MCTSAction action)
{
	if (action.action > m_previousAction.action)
	{
		m_previousAction = action;
		return 1; // if good move
	}
	else if (action.action == m_previousAction.action)
	{
		return 0.5f; // if draw
	}
	else
	{
		m_previousAction = action;
		return 0; // if bad move
	}
}

void MCTSWorldState::reset()
{
	m_isTerminal = false;
	m_winner = 0;
}

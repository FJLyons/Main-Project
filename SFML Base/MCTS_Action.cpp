#include "MCTS_Action.h"

MCTSAction::MCTSAction()
{
	AddChild(ActionState::Search_for_Castle, false);
	action = ActionState::Search_for_Castle;
}

MCTSAction::MCTSAction(ActionState name) :
	action(name)
{
	SetUpAction();
}

MCTSAction::~MCTSAction()
{
}

std::string MCTSAction::GetName()
{
	return GlobalVariables::GetInstance()->stateNames[action];
}

void MCTSAction::AddChild(ActionState child, bool isTerminal)
{
	m_children.push_back(child);
	m_winner.push_back(isTerminal);
}

MCTSAction & MCTSAction::operator=(const MCTSAction & other)
{
	this->m_winner = other.m_winner;
	this->m_children = other.m_children;
	this->action = other.action;
	return *this;
}

void MCTSAction::SetUpAction()
{
	if (action == ActionState::Search_for_Castle)
	{
		AddChild(ActionState::Search_for_Castle, false);
		AddChild(ActionState::Castle_Sighted, true);
	}

	else if (action == ActionState::Castle_Sighted)
	{
		AddChild(ActionState::Castle_Sighted, false);
		AddChild(ActionState::Castle_in_Range, true);
	}

	else if (action == ActionState::Castle_in_Range)
	{
		AddChild(ActionState::Castle_in_Range, false);
		AddChild(ActionState::Attack_Castle, true);
	}

	else if (action == ActionState::Attack_Castle)
	{
		AddChild(ActionState::Attack_Castle, false);
		AddChild(ActionState::Castle_Dead, true);
	}
}

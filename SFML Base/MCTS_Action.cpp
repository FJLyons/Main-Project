#include "MCTS_Action.h"

MCTSAction::MCTSAction()
{
	AddChild(GlobalVariables::ActionState::Search_for_Castle, false);
	action = GlobalVariables::ActionState::Search_for_Castle;
}

MCTSAction::MCTSAction(GlobalVariables::ActionState name) :
	action(name)
{
	SetUpAction();
}

MCTSAction::~MCTSAction()
{
}

std::string MCTSAction::GetName()
{
	return GlobalVariables::getInstance()->stateNames[action];
}

void MCTSAction::AddChild(GlobalVariables::ActionState child, bool isTerminal)
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
	if (action == GlobalVariables::ActionState::Search_for_Castle)
	{
		AddChild(GlobalVariables::ActionState::Search_for_Castle, false);
		AddChild(GlobalVariables::ActionState::Castle_Sighted, true);
	}

	else if (action == GlobalVariables::ActionState::Castle_Sighted)
	{
		AddChild(GlobalVariables::ActionState::Castle_Sighted, false);
		AddChild(GlobalVariables::ActionState::Castle_in_Range, true);
	}

	else if (action == GlobalVariables::ActionState::Castle_in_Range)
	{
		AddChild(GlobalVariables::ActionState::Castle_in_Range, false);
		AddChild(GlobalVariables::ActionState::Attack_Castle, true);
	}

	else if (action == GlobalVariables::ActionState::Attack_Castle)
	{
		AddChild(GlobalVariables::ActionState::Attack_Castle, false);
		AddChild(GlobalVariables::ActionState::Castle_Dead, true);
	}
}

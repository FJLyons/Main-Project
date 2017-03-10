#pragma once

#include "Variables_Global.h"

class MCTSAction
{
public:
	MCTSAction(GlobalVariables::ActionState name = GlobalVariables::ActionState::Search_for_Castle);
	~MCTSAction();

	GlobalVariables::ActionState action;

	// MCTS Actions should be all unit actions

	// MCTS can search all actions at once

	// Each action can lead to full range of actions again

	// Highest value is calculated by MCTS

	// Need to set up all actions before hand
};


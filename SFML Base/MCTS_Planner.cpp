#include "MCTS_Planner.h"

MCTSPlanner::MCTSPlanner() :
	m_iterations(0),
	m_uct_k(sqrt(2)),
	m_maxIterations(100),
	m_maxMillis(0),
	m_simulationDepth(10)
{
}

MCTSPlanner::~MCTSPlanner()
{
}

const int MCTSPlanner::GetIterations() const
{
	return m_iterations;
}

MCTSNode * MCTSPlanner::GetBestUCTChild(MCTSNode * node, float uct_k) const
{
	// sanity check
	if (!node->IsFullyExpanded())
	{
		return NULL;
	}

	float best_utc_score = -std::numeric_limits<float>::max();
	MCTSNode* best_node = NULL;

	// iterate all immediate children and find best UTC score
	int num_children = node->GetNumChildren();
	for (int i = 0; i < num_children; i++)
	{
		MCTSNode* child = node->GetChild(i);

		float uct_exploitation = (float)child->GetValue() / (child->GetNumVisits() + FLT_EPSILON);

		float uct_exploration = sqrt(log((float)node->GetNumVisits() + 1) / (child->GetNumVisits() + FLT_EPSILON));

		float uct_score = uct_exploitation + uct_k * uct_exploration;

		if (uct_score > best_utc_score)
		{
			best_utc_score = uct_score;
			best_node = child;
		}
	}

	return best_node;
}

MCTSNode * MCTSPlanner::GetMostVisitedChild(MCTSNode * node) const
{
	int most_visits = -1;
	MCTSNode* best_node = NULL;

	// iterate all immediate children and find most visited
	int num_children = node->GetNumChildren();
	for (int i = 0; i < num_children; i++)
	{
		MCTSNode* child = node->GetChild(i);

		if (child->GetNumVisits() > most_visits)
		{
			most_visits = child->GetNumVisits();
			best_node = child;
		}
	}

	return best_node;
}

MCTSAction MCTSPlanner::Plan(MCTSWorldState& current_state, std::vector<MCTSWorldState>* explored_states)
{
	//// initialize timer
	//timer.init();

	// initialize root MCTSNode with current state
	MCTSNode root_node(current_state);

	MCTSNode* best_node = NULL;

	// iterate
	m_iterations = 0;

	while (true)
	{
		//// indicate start of loop
		//timer.loop_start();

		// 1. SELECT. Start at root, dig down into tree using UCT on all fully expanded nodes
		MCTSNode* node = &root_node;

		while (!node->IsTerminal() && node->IsFullyExpanded())
		{
			node = GetBestUCTChild(node, m_uct_k);
			// assert(node);	// sanity check
		}

		// 2. EXPAND by adding a single child (if not terminal or not fully expanded)
		if (!node->IsTerminal() && !node->IsFullyExpanded())
		{
			node = node->Expand();
		}

		MCTSWorldState state(node->GetState());

		MCTSAction action;

		// 3. SIMULATE (if not terminal)
		if (!node->IsTerminal())
		{
			for (int i = 0; i < m_simulationDepth; i++)
			{
				if (state.IsTerminal()) 
				{ 
					break; 
				}

				if (state.GetRandomAction(action))
				{
					state.ApplyAction(action);
				}
				else
				{
					break;
				}
			}
		}

		// get rewards vector for all agents
		float rewards = state.Evaluate(action);

		// add to history
		if (explored_states)
		{
			explored_states->push_back(state);
		}

		// 4. BACK PROPAGATION
		while (node)
		{
			node->Update(rewards);
			node = node->GetParent();
		}

		// find most visited child
		best_node = GetMostVisitedChild(&root_node);

		//// indicate end of loop for timer
		//timer.loop_end();

		// exit loop if current total run duration (since init) exceeds max_millis
		//if (m_maxMillis > 0 && timer.Check_duration(m_max_millis)) 
		//{ 
		//	break; 
		//}

		// exit loop if current iterations exceeds max_iterations
		if (m_maxIterations > 0 && m_iterations > m_maxIterations)
		{
			break;

		}

		m_iterations++;
	}

	// return best node's action
	if (best_node)
	{
		return best_node->GetAction();
	}

	// we shouldn't be here
	return MCTSAction();
}

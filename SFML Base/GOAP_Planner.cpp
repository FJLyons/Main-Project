#include "GOAP_Planner.h"

#include <algorithm>
#include <cassert>
#include <iostream>

GOAPPlanner::GOAPPlanner()
{
}

GOAPPlanner::~GOAPPlanner()
{
}

int GOAPPlanner::CalculateHeuristic(const GOAPWorldState& now, const GOAPWorldState& goal) const
{
	return now.DistanceTo(goal);
}

void GOAPPlanner::AddToOpenList(GOAPNode&& node)
{
	// insert maintaining sort order
	auto it = std::lower_bound(begin(m_open), end(m_open), node);
	m_open.emplace(it, std::move(node));
}

GOAPNode& GOAPPlanner::PopAndClose()
{
	assert(!m_open.empty()); // Break program if false

	m_closed.push_back(std::move(m_open.front()));
	m_open.erase(m_open.begin());

	return m_closed.back();
}

bool GOAPPlanner::MemberOfClosed(const GOAPWorldState& worldState) const
{
	if (std::find_if(
		begin(m_closed)
		, end(m_closed)
		, [&](const GOAPNode & node) { return node.m_worldState == worldState; }) == end(m_closed))
	{
		return false;
	}
	return true;
}

std::vector<GOAPNode>::iterator GOAPPlanner::MemberOfOpen(const GOAPWorldState& worldState)
{
	return std::find_if(
		begin(m_open)
		, end(m_open)
		, [&](const GOAPNode & node) { return node.m_worldState == worldState; });
}

//void GOAPPlanner::PrintOpenList() const
//{
//	for (const auto& node : m_open)
//	{
//		std::cout << node << std::endl;
//	}
//}

//void GOAPPlanner::PrintClosedList() const
//{
//	for (const auto& node : m_closed)
//	{
//		std::cout << node << std::endl;
//	}
//}

std::vector<GOAPAction> GOAPPlanner::Plan(const GOAPWorldState& start, const GOAPWorldState& goal, const std::vector<GOAPAction*>& actions)
{
	if (start.MeetsGoal(goal))
	{
		//throw std::runtime_error("Planner cannot plan when the start state and the goal state are the same!");
		return std::vector<GOAPAction>();
	}

	// clear previous results
	m_open.clear();
	m_closed.clear();

	GOAPNode starting_node(start, 0, CalculateHeuristic(start, goal), 0, nullptr);

	m_open.push_back(std::move(starting_node));

	//int iters = 0;
	while (m_open.size() > 0) 
	{
		// Look for Node with the lowest-F-score in the open list. Add it to closed as latest node.
		GOAPNode& current_node(PopAndClose());

		// Is path found
		if (current_node.m_worldState.MeetsGoal(goal))
		{
			std::vector<GOAPAction> the_plan;
			do 
			{
				the_plan.push_back(*current_node.action_);

				auto itr = std::find_if(
					begin(m_open)
					, end(m_open)
					, [&](const GOAPNode & node) { return node.m_id == current_node.m_parent_id; });
				
				if (itr == end(m_open))
				{
					itr = std::find_if(
						begin(m_closed)
						, end(m_closed)
						, [&](const GOAPNode & node) { return node.m_id == current_node.m_parent_id; });
				}

				current_node = *itr;
			} 
			while (current_node.m_parent_id != 0);

			return the_plan;
		}

		// Check each node connected to current
		for (const auto& potential_action : actions)
		{
			if (potential_action->OperableOn(current_node.m_worldState))
			{
				GOAPWorldState best_outcome = potential_action->ActOn(current_node.m_worldState);

				// Skip if already closed
				if (MemberOfClosed(best_outcome))
				{
					continue;
				}

				// Look for a Node with this WorldState in the open list.
				auto outcome_node = MemberOfOpen(best_outcome);

				if (outcome_node == end(m_open))
				{
					// not a member of open list
				    // Make a new node, with current as its parent, recording G & H
					GOAPNode found(best_outcome,
						current_node.m_g + potential_action->GetCost(),
						CalculateHeuristic(best_outcome, goal),
						current_node.m_id,
						potential_action);

					// Add it to the open list and maintaining sort-order
					AddToOpenList(std::move(found));
				}

				else
				{ 
					// already a member of the open list
				    // check if the current G is better than the recorded G
					if (current_node.m_g + potential_action->GetCost() < outcome_node->m_g)
					{
						outcome_node->m_parent_id = current_node.m_id;                     // make current its parent

						outcome_node->m_g = current_node.m_g + potential_action->GetCost(); // recalc G & H
						outcome_node->m_h = CalculateHeuristic(best_outcome, goal);

						outcome_node->action_ = potential_action;

						// resort open list to account for the new F
						std::sort(begin(m_open), end(m_open));
					}
				}
			}
		}
	}

	// If there's nothing left to evaluate, then we have no possible path left
	throw std::runtime_error("A* planner could not find a path from start to goal");
}


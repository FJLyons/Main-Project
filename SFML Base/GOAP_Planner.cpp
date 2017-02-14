#include "GOAP_Planner.h"

#include <algorithm>
#include <cassert>
#include <iostream>

Planner::Planner()
{
}

Planner::~Planner()
{
}

int Planner::CalculateHeuristic(const WorldState& now, const WorldState& goal) const
{
	return now.DistanceTo(goal);
}

void Planner::AddToOpenList(Node&& node)
{
	// insert maintaining sort order
	auto it = std::lower_bound(begin(m_open), end(m_open), node);
	m_open.emplace(it, std::move(node));
}

Node& Planner::PopAndClose()
{
	assert(!m_open.empty()); // Break program if false

	m_closed.push_back(std::move(m_open.front()));
	m_open.erase(m_open.begin());

	return m_closed.back();
}

bool Planner::MemberOfClosed(const WorldState& worldState) const
{
	if (std::find_if(
		begin(m_closed)
		, end(m_closed)
		, [&](const Node & node) { return node.m_worldState == worldState; }) == end(m_closed))
	{
		return false;
	}
	return true;
}

std::vector<Node>::iterator Planner::MemberOfOpen(const WorldState& worldState)
{
	return std::find_if(
		begin(m_open)
		, end(m_open)
		, [&](const Node & node) { return node.m_worldState == worldState; });
}

void Planner::PrintOpenList() const
{
	for (const auto& node : m_open)
	{
		std::cout << node << std::endl;
	}
}

void Planner::PrintClosedList() const
{
	for (const auto& node : m_closed)
	{
		std::cout << node << std::endl;
	}
}

std::vector<Action> Planner::Plan(const WorldState& start, const WorldState& goal, const std::vector<Action>& actions)
{
	if (start.MeetsGoal(goal))
	{
		//throw std::runtime_error("Planner cannot plan when the start state and the goal state are the same!");
		return std::vector<Action>();
	}

	// Feasible we'd re-use a planner, so clear out the prior results
	m_open.clear();
	m_closed.clear();

	Node starting_node(start, 0, CalculateHeuristic(start, goal), 0, nullptr);

	m_open.push_back(std::move(starting_node));

	//int iters = 0;
	while (m_open.size() > 0) 
	{
		// Look for Node with the lowest-F-score on the open list. Switch it to closed,
		// and hang onto it -- this is our latest node.
		Node& current_node(PopAndClose());

		// Is our current state the goal state? If so, we've found a path, yay.
		if (current_node.m_worldState.MeetsGoal(goal))
		{
			std::vector<Action> the_plan;
			do 
			{
				the_plan.push_back(*current_node.action_);

				auto itr = std::find_if(
					begin(m_open)
					, end(m_open)
					, [&](const Node & node) { return node.m_id == current_node.m_parent_id; });
				
				if (itr == end(m_open))
				{
					itr = std::find_if(
						begin(m_closed)
						, end(m_closed)
						, [&](const Node & node) { return node.m_id == current_node.m_parent_id; });
				}

				current_node = *itr;
			} 
			while (current_node.m_parent_id != 0);

			return the_plan;
		}

		// Check each node REACHABLE from current -- in other words, where can we go from here?
		for (const auto& potential_action : actions)
		{
			if (potential_action.OperableOn(current_node.m_worldState))
			{
				WorldState best_outcome = potential_action.ActOn(current_node.m_worldState);

				// Skip if already closed
				if (MemberOfClosed(best_outcome))
				{
					continue;
				}

				// Look for a Node with this WorldState on the open list.
				auto outcome_node = MemberOfOpen(best_outcome);

				if (outcome_node == end(m_open))
				{
					// not a member of open list
				    // Make a new node, with current as its parent, recording G & H
					Node found(best_outcome,
						current_node.m_g + potential_action.GetCost(),
						CalculateHeuristic(best_outcome, goal),
						current_node.m_id,
						&potential_action);

					// Add it to the open list (maintaining sort-order therein)
					AddToOpenList(std::move(found));
				}

				else
				{ 
					// already a member of the open list
				    // check if the current G is better than the recorded G
					if (current_node.m_g + potential_action.GetCost() < outcome_node->m_g)
					{
						//std::cout << "My path to " << p_outcome_node->ws_ << " using " << potential_action.name() << " (combined cost " << current.g_ + potential_action.cost() << ") is better than existing (cost " <<  p_outcome_node->g_ << "\n";
						outcome_node->m_parent_id = current_node.m_id;                     // make current its parent

						outcome_node->m_g = current_node.m_g + potential_action.GetCost(); // recalc G & H
						outcome_node->m_h = CalculateHeuristic(best_outcome, goal);

						outcome_node->action_ = &potential_action;

						// resort open list to account for the new F
						// sorting likely invalidates the p_outcome_node iterator, but we don't need it anymore
						std::sort(begin(m_open), end(m_open));
					}
				}
			}
		}
	}

	// If there's nothing left to evaluate, then we have no possible path left
	throw std::runtime_error("A* planner could not find a path from start to goal");
}


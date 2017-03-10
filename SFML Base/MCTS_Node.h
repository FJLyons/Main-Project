#pragma once

#include <memory>
#include <math.h>
#include <vector>
#include <algorithm>

#include "MCTS_WorldState.h"
#include "MCTS_Action.h"

class MCTSNode
{
public:
	typedef std::shared_ptr< MCTSNode> Ptr;

public:
	MCTSNode(MCTSWorldState& state, MCTSNode* parent = NULL);
	~MCTSNode();

	MCTSNode* Expand();

	void Update(float & rewards);

	const MCTSWorldState& GetState() const;
	const MCTSAction& GetAction() const;

	bool IsFullyExpanded() const;

	bool IsTerminal() const;

	int GetNumVisits() const;

	float GetValue() const;

	int GetDepth() const;

	int GetNumChildren() const;

	MCTSNode* GetChild(int i) const;


	MCTSNode* GetParent() const;


private:
	MCTSWorldState m_state;					// the state of this Tree Node
	MCTSAction m_action;					// the action which led to the state of this Tree Node
	MCTSNode* m_parent;						// parent of this Tree Node

	int m_num_visits;						// number of times TreeNode has been visited
	float m_value;							// value of this TreeNode
	int m_depth;

	std::vector< Ptr > m_children;			// all current children
	std::vector< MCTSAction > m_actions;	// possible actions from this state

	// create a clone of the current state, apply action, and add as child
	MCTSNode* AddChildWithAction(const MCTSAction& new_action);
};


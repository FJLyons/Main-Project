#pragma once

#include "GOAP_Action.h"
#include "GOAP_WorldState.h"

class GOAPNode
{
public:
	GOAPNode();
	~GOAPNode();

	GOAPNode(const GOAPWorldState state, int g, int h, int parent_id, const GOAPAction* action);

	static int last_id_;				// a static that lets us assign incrementing, unique IDs to nodes

	GOAPWorldState m_worldState;		// The state of the world at this node.
	int m_id;							// the unique ID of this node
	int m_parent_id;					// the ID of this node's immediate predecessor
	int m_g;							// The A* cost from 'start' to 'here'
	int m_h;							// The estimated remaining cost to 'goal' form 'here'
	const GOAPAction* action_;			// The action that got us here (for replay purposes)


	// F -- which is simply G+H -- is autocalculated
	int f() const 
	{
		return m_g + m_h;
	}

	//friend std::ostream& operator<<(std::ostream& out, const GOAPNode& n);
};

bool operator<(const GOAPNode& lhs, const GOAPNode& rhs);

//inline std::ostream& operator<<(std::ostream& outStream, const GOAPNode& node)
//{
//	outStream << "Node { id:"  << node.m_id
//		<< " parent:"  << node.m_parent_id
//		<< " F:" << node.f()
//		<< " G:" << node.m_g
//		<< " H:" << node.m_h;
//
//	outStream << ", " << node.m_worldState << "}";
//	return outStream;
//}


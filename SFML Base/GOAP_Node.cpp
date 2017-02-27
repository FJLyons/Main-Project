#include "GOAP_Node.h"
#include <iostream>

int GOAPNode::last_id_ = 0;

GOAPNode::GOAPNode()
	: m_g(0)
	, m_h(0)
{
	m_id = ++last_id_;
}

GOAPNode::GOAPNode(const GOAPWorldState state, int g, int h, int parent_id, const GOAPAction* action)
	: m_worldState(state)
	, m_g(g)
	, m_h(h)
	, m_parent_id(parent_id)
	, action_(action)
{
	m_id = ++last_id_;
}

GOAPNode::~GOAPNode()
{
}

bool operator<(const GOAPNode& lhs, const GOAPNode& rhs)
{
	return lhs.f() < rhs.f();
}

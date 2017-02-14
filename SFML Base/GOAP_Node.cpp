#include "GOAP_Node.h"
#include <iostream>

int Node::last_id_ = 0;

Node::Node() 
	: m_g(0)
	, m_h(0)
{
	m_id = ++last_id_;
}

Node::Node(const WorldState state, int g, int h, int parent_id, const Action* action) 
	: m_worldState(state)
	, m_g(g)
	, m_h(h)
	, m_parent_id(parent_id)
	, action_(action)
{
	m_id = ++last_id_;
}

Node::~Node()
{
}

bool operator<(const Node& lhs, const Node& rhs)
{
	return lhs.f() < rhs.f();
}

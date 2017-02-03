#pragma once

// SFML Headers
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <map>
#include <vector>
#include <queue>

using namespace std;

// Action Present in Agent
#include "Action.h"
#include "Agent.h"

class Node 
{
public:
	Node(Node parent, float runningCost, map<string, bool> state, Action action);
	~Node();

	Node* parent;
	float runningCost;
	map<string, bool> state;
	Action* action;
};

class GOAPPlanner
{
public:
	GOAPPlanner();
	~GOAPPlanner();

	priority_queue<Action*> Plan(Agent* age, vector<Action*>* act, map<string, bool> worldState, map<string, bool> goal);

private:
	bool BuildGraph(Node parent, vector<Node> leaves, vector<Action*>* usableActions, map<string, bool> goal);

	vector<Action*>* ActionSubset(vector<Action*>* actions, Action* removeMe);

	bool InState(map<string, bool> test, map<string, bool> state);

	map<string, bool> populateState(map<string, bool> currentState, map<string, bool> stateChange);

};
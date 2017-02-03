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
class Action;

#include "State.h"


class Agent
{
public:
	Agent();
	~Agent();

private:
	vector<State*>* stateMachine = new vector<State*>();
	State* idleState = new State();
	State* moveToState = new State();
	State* performActionState = new State();

	vector<Action*>* actionsAvailable = new vector<Action*>();
	priority_queue<Action*>* actionsRunning = new priority_queue<Action*>();

public:
	void AddAction(Action act);
	Action GetAction();
	void RemoveAction(Action act);

private:
	void CreateIdleState();
	void CreateMoveToState();
	void CreatePerformActionState();

	void FindDataProvider();
	void LoadActions();
};


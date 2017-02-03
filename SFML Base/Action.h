#pragma once

#include <map>
#include <vector>
#include <queue>

using namespace std;

// Agent Present in Action
#include "Agent.h"
class Agent;

class Action
{
public:
	Action();
	~Action();

private:
	map<string, bool>* preconditions = new map<string, bool>; // HashSet<KeyValuePair<string , object>> 
	map<string, bool>* effects = new map<string, bool>;

	bool m_inRange = false;

public:
	float cost = 1.0f;

	//Agent* target;

	void DoReset();
	void Reset();

	bool IsDone();

	//bool CheckProceduralPrecondition(Agent* age);
	//bool Perform(Agent* age);

	bool RequiresInRange();
	bool GetInRange();
	void SetInRange(bool range);

	void AddPreCondition(string key, bool value);
	void RemovePreCondition(string key);

	void AddEffect(string key, bool value);
	void RemoveEffect(string key);

	map<string, bool>* GetPreconditions();
	map<string, bool>* GetEffects();
};


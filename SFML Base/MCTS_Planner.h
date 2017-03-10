#pragma once

#include "MCTS_Node.h"
//#include "MSALoopTimer.h"
#include <cfloat>

class MCTSPlanner
{
public:
	MCTSPlanner();
	~MCTSPlanner();

private:
	//LoopTimer timer;
	int m_iterations;

public:
	float m_uct_k;						// k value in UCT function. default = sqrt(2)
	unsigned int m_maxIterations;		// do a maximum of this many iterations (0 to run till end)
	unsigned int m_maxMillis;			// run for a maximum of this many milliseconds (0 to run till end)
	unsigned int m_simulationDepth;	// how many ticks (frames) to run simulation for

	// const LoopTimer & get_timer() const;

	const int GetIterations() const;


public:
	MCTSNode* GetBestUCTChild(MCTSNode* node, float uct_k) const;


	MCTSNode* GetMostVisitedChild(MCTSNode* node) const;


	MCTSAction Plan(MCTSWorldState& current_state, std::vector<MCTSWorldState>* explored_states = nullptr);

};


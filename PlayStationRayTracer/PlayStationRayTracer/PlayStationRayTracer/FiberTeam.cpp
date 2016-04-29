#include "FiberTeam.h"

void FiberTeam::fiberEntryLeader(uint64_t argOnInitialize, uint64_t argOnRun)
{
	int i = 0;
	int ret = SCE_OK;

	printf("entry : My ID=%#1x, switched from %s/n", argOnInitialize, "OS thread");

	Fiber *myFib = (Fiber *)argOnInitialize;

	//get debug Info
	SceFiber *fiber;
	ret = sceFiberGetSelf(&fiber);
	assert(ret == SCE_OK);

	printFiberDebugInfo(fiber);

	while (1) {
		for (i = 0;i<WAIT_FRAME_LEADER)



	}
}

void FiberTeam::fiberEntryFollower(uint64_t argOnInitialize, uint64_t argOnRun)
{
}

void FiberTeam::fiberEntryTail(uint64_t argOnInitialize, uint64_t argOnRun)
{
}

void FiberTeam::printFiberDebugInfo(SceFiber * fiber)
{
}

inline void FiberTeam::setLeaderFollowingPos(Fiber * leader)
{
}

inline void FiberTeam::leaderFiberSwitch(Fiber * leader)
{
}


int FiberTeam::initialize(void)
{
	return 0;
}

int FiberTeam::update(void)
{
	return 0;
}

int FiberTeam::finalize(void)
{
	return 0;
}



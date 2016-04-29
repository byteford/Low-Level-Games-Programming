#pragma once
#include <sce_fiber.h>
#include "definitions.h"
#include <assert.h>
typedef struct Fiber
{
	SceFiber fiber;
	SceFiber *nextFiber;

} Fiber;

class FiberTeam
{
private:
	Fiber m_leader __attribute__((aligned(SCE_FIBER_ALIGNMENT)));
	Fiber m_followers[N_FOLLOWERS] __attribute__((aligned(SCE_FIBER_ALIGNMENT)));
	SceFiber m_tailFiber __attribute__((aligned(SCE_FIBER_ALIGNMENT)));
	char	m_contextBuffer[N_FOLLOWERS + 2][SIZE_CONTEXT] __attribute__((aligned(SCE_FIBER_ALIGNMENT)));

	__attribute__((noreturn));
	static void fiberEntryLeader(uint64_t argOnInitialize, uint64_t argOnRun);
	__attribute__((noreturn));
	static void fiberEntryFollower(uint64_t argOnInitialize, uint64_t argOnRun);
	__attribute__((noreturn));
	static void fiberEntryTail(uint64_t argOnInitialize, uint64_t argOnRun);
	static void printFiberDebugInfo(SceFiber *fiber);
	static inline void setLeaderFollowingPos(Fiber *leader);
	static inline void leaderFiberSwitch(Fiber *leader);

public:
	int initialize(void);
	int update(void);
	int finalize(void);
};


#pragma once
#include "Vec3.h"
class MoveCom
{
	int startFrame, endFrame, sphere, amountOfFrames;
	Vec3f pos, movementPerFrame;
public:
	MoveCom(int startFrame, int endFrame, int sphere, float x, float y, float z);
	~MoveCom();
	int GetSphere();
	Vec3f GetPosAtFrame(int frameNum);
};

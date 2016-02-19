#pragma once
#include "Vec3.h"
class MoveCom
{
	int startFrame, endFrame, sphere, amountOfFrames;
	Vec3f pos, movementPerFrame;
public:
	MoveCom(int startFrame, int endFrame, int sphere,int x,int y,int z);
	~MoveCom();
	int GetSphere();
	Vec3f GetPosAtFrame(int frameNum);
};


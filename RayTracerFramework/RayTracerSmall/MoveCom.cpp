#include "MoveCom.h"


MoveCom::MoveCom(int startFrame, int endFrame, int sphere, int x, int y, int z)
{
	this->startFrame = startFrame;
	this->endFrame = endFrame;
	this->sphere = sphere;
	pos.x = x;
	pos.y = y;
	pos.z = z;
	amountOfFrames = endFrame - startFrame;
	movementPerFrame.x = pos.x / amountOfFrames;
	movementPerFrame.y = pos.y / amountOfFrames;
	movementPerFrame.z = pos.z / amountOfFrames;
}

MoveCom::~MoveCom()
{
}

int MoveCom::GetSphere()
{
	return sphere;
}

Vec3f MoveCom::GetPosAtFrame(int frameNum)
{
	if (frameNum > startFrame) {
		if (frameNum < endFrame) {
		int temp =frameNum - startFrame;
		return(pos * temp);
		}
		else {
			return pos;
		}
	}
	return Vec3f();
}

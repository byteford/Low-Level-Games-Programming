#pragma once
#include <functional>
#include <vector>
#include "Sphere.h"
class Command
{
private:
	void(Sphere::*method)(Vec3f);
	Vec3f arg;
	Sphere* sphere;
public:
	Command(void(Sphere::*meth)(Vec3f), Vec3f ar, Sphere*sph);
	~Command();
	void RunCommand();
};

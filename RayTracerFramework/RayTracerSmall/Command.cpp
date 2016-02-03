#include "Command.h"



Command::Command(void(Sphere::*meth)(Vec3f), Vec3f ar, Sphere*sph)
{
	method = meth;
	arg = ar;
	sphere = sph;
}


Command::~Command()
{
}

void Command::RunCommand(){
	auto f = std::bind(method, sphere, arg);
	f();
}
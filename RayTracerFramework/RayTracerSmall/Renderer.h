#pragma once
#include "Vec3.h"
#include <vector>
#include "Sphere.h"
#include "definitions.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
class Renderer
{
public:
	Renderer();
	~Renderer();
	float mix(const float &a, const float &b, const float &mix);
	Vec3f trace(
		const Vec3f &rayorig,
		const Vec3f &raydir,
		const std::vector<Sphere> &spheres,
		const int &depth);
	void render(const std::vector<Sphere> &spheres, int iteration, const char* folderName);
};


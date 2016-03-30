#pragma once
#include "Vec3.h"
#include <vector>
#include "Sphere.h"
#include "definitions.h"
#include "allocator.h"
#include <fstream>
class Renderer
{
private:
	static const size_t kOnionMemorySize = 64 * 1024 * 1024;
public:
	Renderer();
	~Renderer();
	float mix(const float &a, const float &b, const float &mix);
	Vec3f trace(
		const Vec3f &rayorig,
		const Vec3f &raydir,
		const std::vector<Sphere> &spheres,
		const int &depth);
	void render(const std::vector<Sphere> &spheres, int iteration, int threadNumber);
};


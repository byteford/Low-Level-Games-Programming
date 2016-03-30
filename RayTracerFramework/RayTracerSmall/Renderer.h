#pragma once
#include "SphScene.h"
#include "Vec3.h"
#include <vector>
#include "Sphere.h"
#include "definitions.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

#include <thread>
#include <future>
class Renderer
{
public:
	Renderer();
	~Renderer();
	Vec3f* pixel;
	std::thread readThread;
	float mix(const float &a, const float &b, const float &mix);
	//Vec3f trace(
	//	const Vec3f &rayorig,
	//	const Vec3f &raydir,
	//	const std::vector<Sphere> &spheres,
	//	const int &depth);
	Vec3f trace(
		const Vec3f &rayorig,
		const Vec3f &raydir,
		SphScene scene,
		const int &depth);
	void traceThread(
		const Vec3f &rayorig,
		const Vec3f &raydir,
		SphScene scene,
		const int &depth,
		int y,
		int width,
		int x);
	//void render(const std::vector<Sphere> &spheres, int iteration, const char* folderName);
	void render(SphScene scene, int iteration, const char* folderName);
	void ThreadFile(std::string filename, unsigned width, unsigned height, Vec3f* image);
	void ThreadRend(unsigned width, 
		unsigned height, 
		float angle, 
		float aspectratio, 
		float invWidth, float invHeight, SphScene& scene, Vec3f* pixel);
	void JoinReadThread();
	void ThreadSplitter(unsigned startHeight,
		unsigned endHeight,
		unsigned startWidth,
		unsigned endWidth,
		unsigned Width,
		SphScene& scene,
		float invWidth, float invHeight, float angle, float aspectratio);
	const char * workOutInt(int itteration);
};


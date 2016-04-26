#pragma once
#include "Vec3.h"
#include <vector>
#include "Sphere.h"
#include "definitions.h"
#include "allocator.h"
#include <sstream>
#include <fstream>
#include <sce_fiber.h>
#include <fios2.h>
#include <libsysmodule.h>
#include<assert.h>
#include <string>
#include "SphScene.h"
#include <thread>
class Renderer
{
private:
	static const size_t kOnionMemorySize = 64 * 1024 * 1024;
	SceFiosOp op[3];
	SceFiosOpenParams openParams;
	SceFiosFH writeFH;
	SceFiosSize result;

	Vec3f* pixel;
	std::thread readThread;

	void * buffer;
	Vec3f *image;
	//Vec3f *pixel;
	LinearAllocator onionAllocator;

	
public:
	Renderer();
	~Renderer();
	float mix(const float &a, const float &b, const float &mix);
	Vec3f trace(
		const Vec3f &rayorig,
		const Vec3f &raydir,
		SphScene scene,
		const int &depth);
	void render(SphScene scene, int iteration, const char* folderName);
};


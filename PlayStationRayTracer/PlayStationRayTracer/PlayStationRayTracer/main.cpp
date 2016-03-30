#include <stdio.h>
#include <stdlib.h>
#include <scebase.h>
#include <kernel.h>
#include <gnmx.h>
#include <video_out.h>

#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#include <algorithm>
#include <sstream>
#include <string.h>

// Time precision
#include <chrono>

// Threading
#include <thread>

#include "allocator.h"

#include "Vec3.h"
#include "Sphere.h"
#include "definitions.h"
#include "Renderer.h"
//static const size_t kOnionMemorySize = 64 * 1024 * 1024;

std::chrono::time_point<std::chrono::system_clock> start;
std::chrono::time_point<std::chrono::system_clock> end;
std::chrono::duration<double> total_elapsed_time;

static const int num_threads = 10;

using namespace sce;
using namespace sce::Gnmx;




void BasicRender(int iteration, Renderer rend)
{
	std::vector<Sphere> spheres;

	spheres.push_back(Sphere(Vec3f(0.0, -10004, -20), 10000, Vec3f(0.20, 0.20, 0.20), 0, 0.0));
	spheres.push_back(Sphere(Vec3f(iteration, 0, -20), 1, Vec3f(1.00, 0.32, 0.36), 1, 0.5)); // Radius++ change here
	spheres.push_back(Sphere(Vec3f(5.0, -1, -15), 2, Vec3f(0.90, 0.76, 0.46), 1, 0.0));
	spheres.push_back(Sphere(Vec3f(5.0, 0, -25), 3, Vec3f(0.65, 0.77, 0.97), 1, 0.0));
	rend.render(spheres, iteration, 1);

	spheres.clear();
}
int main(int argc, char **argv)
{
	Renderer rend;
	for (int i = 0; i < 10; i++)
	{
		BasicRender(i, rend);
		std::cout << i << " done" <<std::endl;
		std::cout.flush();
	}
	
	return 0;
}
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
#include "SphScene.h"
#include "Vec3.h"
#include "Sphere.h"
#include "definitions.h"
#include "Renderer.h"
#include "Logger.h"
#include <fios2.h>
#include<assert.h>
//static const size_t kOnionMemorySize = 64 * 1024 * 1024;
using namespace sce;
using namespace sce::Gnmx;

SphScene scene;


std::chrono::time_point<std::chrono::system_clock> start;
std::chrono::time_point<std::chrono::system_clock> end;
std::chrono::duration<double> total_elapsed_time;


std::stringstream* folder;


int frames, frameRate, seconds;

void SetThingsUp(int argc, char **argv){
	time_t timenow;
	time(&timenow);
	folder = new std::stringstream();
	folder->str("");
	*folder << "/app0/SceneOut/" << timenow;
	Logger::SetFolder(folder->str());
	std::stringstream cons;
	for (int i = 0; i < argc; i++)
	{

		cons.str(argv[i]);
		if (cons.str() == "-fr") {
			frameRate = std::atoi(argv[i + 1]);
			Logger::output(std::to_string(frameRate));
			Logger::output("\n");
		}
		else if (cons.str() == "-s") {
			seconds = std::atoi(argv[i + 1]);
			Logger::output(std::to_string(seconds));
			Logger::output("\n");
		}
	}
	frames = frameRate * seconds;
	//std::cout << "Seconds: " << seconds << " FrameRate: " << frameRate << "frames: " << frames;
	scene.LoadSpheresFromFile();
	std::string temp = folder->str();
	sceFiosDirectoryCreateSync(NULL, "/app0/SceneOut/");
	sceFiosDirectoryCreateSync(NULL, temp.c_str());
}

void PostStuff(){
	/*start = std::chrono::system_clock::now();


	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_time = end - start;
	total_elapsed_time += elapsed_time;

	std::stringstream* stream = new std::stringstream();


	*stream << "**********************" << std::endl;
	*stream << "Finished video render in " << elapsed_time.count() << std::endl;
	*stream << "**********************" << std::endl;
	*stream << "**********************" << std::endl;
	*stream << "Total Render Time: " << total_elapsed_time.count() << std::endl;
	*stream << "**********************" << std::endl;*/
}

void UpdateLoop(Renderer* rend) {
	std::stringstream stream;
	for (int r = 0; r <= frames; r++)
	{
		scene.Update(r);
		//std::cout << "Start Render \n";
		stream.str("Start Render ");
		stream << r << "\n";
		Logger::output(&stream);
		start = std::chrono::system_clock::now();
		rend->render(scene, r, folder->str().c_str());
		end = std::chrono::system_clock::now();
		//std::chrono::duration<double> elapsed_time = end - start;
		//total_elapsed_time += elapsed_time;
		//std::stringstream* stream = new std::stringstream();
		//*stream << "Finished image " << r << " render in " << elapsed_time.count() << std::endl;
		//Logger::output(stream);
		//std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
	}
}

/*void BasicRender(int iteration, Renderer rend)
{
	std::vector<Sphere> spheres;

	spheres.push_back(Sphere(Vec3f(0.0, -10004, -20), 10000, Vec3f(0.20, 0.20, 0.20), 0, 0.0));
	spheres.push_back(Sphere(Vec3f(iteration, 0, -20), 1, Vec3f(1.00, 0.32, 0.36), 1, 0.5)); // Radius++ change here
	spheres.push_back(Sphere(Vec3f(5.0, -1, -15), 2, Vec3f(0.90, 0.76, 0.46), 1, 0.0));
	spheres.push_back(Sphere(Vec3f(5.0, 0, -25), 3, Vec3f(0.65, 0.77, 0.97), 1, 0.0));
	rend.render(spheres, iteration, 1);

	spheres.clear();
}*/
int main(int argc, char **argv)
{
	Renderer rend;
	frameRate = 10;
	seconds = 10;
	SetThingsUp(argc, argv);
	/*for (int i = 0; i < 10; i++)
	{
		//BasicRender(i, rend);
		std::cout << i << " done" <<std::endl;
		std::cout.flush();
	}*/
	UpdateLoop(&rend);
	PostStuff();
	return 0;
}
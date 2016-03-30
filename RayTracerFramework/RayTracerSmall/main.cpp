// [header]
// A very basic raytracer example.
// [/header]
// [compile]
// c++ -o raytracer -O3 -Wall raytracer.cpp
// [/compile]
// [ignore]
// Copyright (C) 2012  www.scratchapixel.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// [/ignore]
#include <stdlib.h>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>
// Windows only
#include <algorithm>
#include <sstream>
#include <string.h>
#include "Sphere.h"
#include "definitions.h"
#include "Renderer.h"
#include "Logger.h"
#include <chrono>
#include <time.h>

SphScene sce;
Renderer rend;

std::stringstream* folder;

std::chrono::time_point<std::chrono::system_clock> start;
std::chrono::time_point<std::chrono::system_clock> end;
std::chrono::duration<double> total_elapsed_time;

int frames;
int frameRate;
int seconds;
void SetThingsUp(int argc, char **argv) {

	time_t timenow;
	time(&timenow);
	folder = new std::stringstream();
	folder->str("");
	*folder << "SceneOut\\" << timenow;
	Logger::SetFolder(folder->str());

	std::stringstream cons;
	for (int i = 0; i < argc;i++)
	{
		
		cons.str(argv[i]);
		if (cons.str() == "-fr") {
			frameRate = std::atoi(argv[i + 1]);
			//std::cout << frameRate << "\n";
			Logger::output(std::to_string(frameRate)); 
			Logger::output("\n");
		}
		else if (cons.str() == "-s") {
			seconds = std::atoi(argv[i + 1]);
			//std::cout << seconds << "\n";
			Logger::output(std::to_string(seconds));
			Logger::output("\n");
		}
	}
	frames = frameRate * seconds;


	sce.LoadSpheresFromFile();

	
	//time_t now = time(0);
	

	std::stringstream ss;

	ss << "mkdir " << folder->str();
	system(ss.str().c_str());

}
void PostStuff() {
	start = std::chrono::system_clock::now();
	rend.JoinReadThread();
	std::string vidFilename = "\\out.mp4";
#ifdef _DEBUG
	std::stringstream ffmp;
	ffmp << "ffmpeg -f image2 -r " << frameRate << " -i " << folder->str() << "\\spheres%d.ppm -b 600k " << folder->str() << vidFilename;
	//ffmp << "ffmpeg";
	std::cout << ffmp.str();
	system(ffmp.str().c_str());
#else
	std::stringstream ffmp;
	ffmp << "ffmpeg -f image2 -r " << frameRate << " -i " << folder->str() << "\\spheres%d.ppm -b 600k " << folder->str() << vidFilename;
	//ffmp << "ffmpeg";
	std::cout << ffmp.str();
	system(ffmp.str().c_str());
#endif
	end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_time = end - start;
	total_elapsed_time += elapsed_time;

	std::stringstream* stream = new std::stringstream();


	*stream << "**********************" << std::endl;
	*stream << "Finished video render in " << elapsed_time.count() << std::endl;
	*stream << "**********************" << std::endl;
	*stream << "**********************" << std::endl;
	*stream << "Total Render Time: " << total_elapsed_time.count() << std::endl;
	*stream << "**********************" << std::endl;
	Logger::output(stream);
	std::stringstream temp;
	temp << folder->str() << vidFilename;
	system(temp.str().c_str());
}
void UpdateLoop() {
	for (int r = 0; r <= frames; r++)
	{
		sce.Update(r);
		//std::cout << "Start Render \n";
		Logger::output("Start Render \n");
		start = std::chrono::system_clock::now();
		rend.render(sce, r, folder->str().c_str());
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_time = end - start;
		total_elapsed_time += elapsed_time;
		std::stringstream* stream = new std::stringstream();
		*stream << "Finished image "<< r <<" render in " << elapsed_time.count()<< std::endl;
		Logger::output(stream);
		//std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
	}
}
int main(int argc, char **argv)
{
	srand(13);
	frameRate = 10;
	seconds = 10;
	SetThingsUp(argc, argv);
	UpdateLoop();
	PostStuff();
	system("pause");
	return 0;
}


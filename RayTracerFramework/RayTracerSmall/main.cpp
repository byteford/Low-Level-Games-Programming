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


void SmoothScaling()
{
	std::vector<Sphere> spheres;
	// Vector structure for Sphere (position, radius, surface color, reflectivity, transparency, emission color)
	Renderer rend;
	for (float r = 0; r <= 100; r++)
	{
		spheres.push_back(Sphere(Vec3f(0.0, -10004, -10), 10000, Vec3f(0.20f, 0.20f, 0.20f), 1, 0.0));
		spheres.push_back(Sphere(Vec3f(0.0, 0, -10), r / 100, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5)); // Radius++ change here
		spheres.push_back(Sphere(Vec3f(5.0, -1, -5), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0));
		spheres.push_back(Sphere(Vec3f(5.0, 0, -15), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0));
		//rend.render(spheres, r, "help");
		std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
		// Dont forget to clear the Vector holding the spheres.
		spheres.clear();

	}
}
//[comment]
// In the main function, we will create the scene which is composed of 5 spheres
// and 1 light (which is also a sphere). Then, once the scene description is complete
// we render that scene, by calling the render() function.
//[/comment]
int main(int argc, char **argv)
{
	// This sample only allows one choice per program execution. Feel free to improve upon this
	srand(13);
	//BasicRender();
	//SimpleShrinking();
	//SmoothScaling();
	
	SphScene sce;
	Renderer rend;
	//sce.SmoothScaling();

	sce.AddSphere(Vec3f(0.0, -10004, -10), 10000, Vec3f(0.20f, 0.20f, 0.20f), 1, 0.0);
	sce.AddSphere(Vec3f(0.0, 0, -10), 0, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5);
	sce.AddSphere(Vec3f(5.0, -1, -5), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0);
	sce.AddSphere(Vec3f(5.0, 0, -15), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0);




	for (int r = 0; r <= 100; r++)
	{
		sce.Update();
		rend.render(sce, r, "help");
		std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
	}

	return 0;
}


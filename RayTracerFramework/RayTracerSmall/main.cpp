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

//[comment]
// In the main function, we will create the scene which is composed of 5 spheres
// and 1 light (which is also a sphere). Then, once the scene description is complete
// we render that scene, by calling the render() function.
//[/comment]
int main(int argc, char **argv)
{
	srand(13);

	SphScene sce;
	Renderer rend;

	sce.AddSphere(Vec3f(0.0, -10004, -10), 10000, Vec3f(0.20f, 0.20f, 0.20f), 1, 0.0);
	sce.AddSphere(Vec3f(0.0, 0, -10), 0, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5);
	sce.AddSphere(Vec3f(5.0, -1, -5), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0);
	sce.AddSphere(Vec3f(5.0, 0, -15), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0);

	sce.AddCommand(&Sphere::increaseRadius,Vec3f(0.1f,0,0), sce.getSphereRef(1));
	sce.AddCommand(&Sphere::Move, Vec3f(1, 0, 0), sce.getSphereRef(2));
	
	std::cout << system("cd Scene");
	
	system("mkdir SceneOut");

	std::stringstream ss;
	
	ss << "mkdir sceneOut'\'25";
	system(ss.str().c_str());

	for (int r = 0; r <= 100; r++)
	{
		sce.Update();
		rend.render(sce, r, "SceneOut");
		std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
	}

	return 0;
}


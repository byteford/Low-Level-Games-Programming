#pragma once
#include <vector>
#include "Sphere.h"
#include <functional>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Logger.h"
#include "MoveCom.h"
class SphScene
{
private:
	std::vector<Sphere>* spheres;
	std::vector<MoveCom>* moves;
public:
	SphScene();
	~SphScene();
	void Update(int frameNum);
	void AddSphere(
		const Vec3f &c,
		const float &r,
		const Vec3f &sc,
		const float &refl,
		const float &transp,
		const Vec3f &ec);
	Sphere getSphere(int num) const;
	bool DoesSphereIntersect(int spherNum, const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const;
	Sphere* getSphereRef(int num);
	int GetSize() const;
	void LoadSpheresFromFile();
	void AddSphere(std::string str);
	void LoadMove(std::string str);
};


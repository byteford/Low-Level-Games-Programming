#pragma once
#include <vector>
#include "Sphere.h"
#include <functional>
#include <sstream>
#include <iostream>
#include <fstream>
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
	void AddSphere(const Vec3f &c,
		const float &r,
		const Vec3f &sc,
		const float &refl = 0,
		const float &transp = 0,
		const Vec3f &ec = 0);
	Sphere getSphere(int num) const;
	Sphere* getSphereRef(int num);
	int GetSize() const;
	void LoadSpheresFromFile();
	void AddSphere(std::string str);
	void LoadMove(std::string str);
};


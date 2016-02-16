#pragma once
#include <vector>
#include "Sphere.h"
#include <functional>
#include "Command.h"
#include <sstream>
#include <iostream>
#include <fstream>
class SphScene
{
private:
	std::vector<Sphere>* spheres;
	std::vector<Command> commands;
public:
	SphScene();
	~SphScene();
	void Update();
	void AddSphere(const Vec3f &c,
		const float &r,
		const Vec3f &sc,
		const float &refl = 0,
		const float &transp = 0,
		const Vec3f &ec = 0);
	Sphere getSphere(int num) const;
	Sphere* getSphereRef(int num);
	int GetSize() const;
	void AddCommand(void(Sphere::*method)(Vec3f), Vec3f arg, Sphere* sph);
	void RunCommand(int commandNo);
	void LoadSpheresFromFile();
	void AddSphere(std::string str);
};


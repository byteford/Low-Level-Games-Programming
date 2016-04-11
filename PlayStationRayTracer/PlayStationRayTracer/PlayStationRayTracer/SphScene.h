#pragma once
#include <vector>
#include "Sphere.h"
class SphScene
{
private:
	std::vector<Sphere>* spheres;
public:
	SphScene();
	~SphScene();
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
};


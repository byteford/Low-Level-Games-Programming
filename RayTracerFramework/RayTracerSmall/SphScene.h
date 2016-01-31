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
	void Update();
	void AddSphere(const Vec3f &c,
		const float &r,
		const Vec3f &sc,
		const float &refl = 0,
		const float &transp = 0,
		const Vec3f &ec = 0);
	Sphere getSphere(int num) const;
	int GetSize() const;
};


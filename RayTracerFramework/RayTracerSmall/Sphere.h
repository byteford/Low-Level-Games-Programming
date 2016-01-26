#pragma once
#include "Vec3.h"
#include <cmath>
class Sphere
{
	typedef Vec3<float> Vec3f;
private:
		Vec3f center;                           /// position of the sphere
		float radius, radius2;                  /// sphere radius and radius^2
		Vec3f surfaceColor, emissionColor;      /// surface color and emission (light)
		float transparency, reflection;         /// surface transparency and reflectivity
public:
	Sphere(
		const Vec3f &c,
		const float &r,
		const Vec3f &sc,
		const float &refl =0,
		const float &transp =0,
		const Vec3f &ec =0);
	~Sphere();
	bool intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const;
	Vec3f getCenter() const;
	float getRadius() const;
	float getRadiusSquare() const;
	Vec3f getSurfaceColor() const;
	Vec3f getEmissionsColor() const;
	float getTransparency() const;
	float getReflection() const;
};


#include "Sphere.h"

Sphere::Sphere(
			const Vec3f &c,
			const float &r,
			const Vec3f &sc,
			const float &refl ,
			const float &transp ,
			const Vec3f &ec ) :
			center(c), radius(r), radius2(r * r), surfaceColor(sc), emissionColor(ec),
			transparency(transp), reflection(refl)
		{ /* empty */
		}


Sphere::~Sphere()
{
}
bool Sphere::intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const
	{
		Vec3f l = center - rayorig;
		float tca = l.dot(raydir);
		if (tca < 0) return false;
		float d2 = l.dot(l) - tca * tca;
		if (d2 > radius2) return false;
		float thc = sqrt(radius2 - d2);
		t0 = tca - thc;
		t1 = tca + thc;

		return true;
	}

Vec3f Sphere::getCenter() const{ return center; }
float Sphere::getRadius() const{ return radius; }
float Sphere::getRadiusSquare() const{ return radius2; }
Vec3f Sphere::getSurfaceColor() const{ return surfaceColor; }
Vec3f Sphere::getEmissionsColor() const{ return emissionColor; }
float Sphere::getTransparency() const{ return transparency; }
float Sphere::getReflection() const{ return reflection; }

void Sphere::setCenter(Vec3f newPos)
{
	center = newPos;
}

void Sphere::Move(float x, float y, float z)
{
	Move(Vec3f(x, y, z));
}

void Sphere::Move(Vec3f amount)
{
	center += amount;
}

void Sphere::SetRadius(float r)
{
	radius = r;
	radius2 = r*r;
}

void Sphere::increaseRadius(float r)
{
	SetRadius(getRadius() + r);
}

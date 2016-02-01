#include "SphScene.h"



SphScene::SphScene()
{
	spheres = new std::vector<Sphere>();
}


SphScene::~SphScene()
{
}


void SphScene::Update()
{
	//spheres->at(1).increaseRadius(0.01f);
	RunCommand(&spheres->at(1));
	
}

void SphScene::AddSphere(const Vec3f & c, const float & r, const Vec3f & sc, const float & refl, const float & transp, const Vec3f & ec)
{
	spheres->push_back(Sphere(c, r, sc, refl, transp, ec));
}

Sphere SphScene::getSphere(int num) const
{
	return (*spheres)[num];
}

int SphScene::GetSize() const
{
	return spheres->size();
}
void SphScene::test(float temp, int test) {


}
void SphScene::RunCommand(Sphere* sph)
{
	void(Sphere::*p_func)(float) = &Sphere::increaseRadius;
	auto f = std::bind(p_func, sph, 0.01f);
	f();
	//p_func(0.01f);
}

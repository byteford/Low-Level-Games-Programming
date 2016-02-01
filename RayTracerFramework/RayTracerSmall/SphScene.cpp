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
	spheres->at(1).increaseRadius(0.01f);
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

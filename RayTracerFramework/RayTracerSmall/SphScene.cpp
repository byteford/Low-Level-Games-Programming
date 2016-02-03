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
	for (int i = 0; i < commands.size(); i++){
		RunCommand(i);

	}
	//spheres->at(2).Move(Vec3f(1, 0, 0));
	/*RunCommand(0);
	RunCommand(1);*/
}

void SphScene::AddSphere(const Vec3f & c, const float & r, const Vec3f & sc, const float & refl, const float & transp, const Vec3f & ec)
{
	spheres->push_back(Sphere(c, r, sc, refl, transp, ec));
}

Sphere SphScene::getSphere(int num) const
{
	return (*spheres)[num];
}

Sphere* SphScene::getSphereRef(int num){
	return &spheres->at(num);
}

int SphScene::GetSize() const
{
	return spheres->size();
}
void SphScene::AddCommand(void(Sphere::*method)(Vec3f), Vec3f arg, Sphere* sph){
	commands.push_back(Command(method, arg, sph));
}
void SphScene::RunCommand(int commandNo)
{
	commands[commandNo].RunCommand();
	/*void(Sphere::*)(Vec3f) temp;
	temp.push_back(&Sphere::increaseRadius);
	void(Sphere::*p_func)(float) = &Sphere::increaseRadius;
	auto f = std::bind(temp[0], sph, 0.01f);
	f();*/
	//p_func(0.01f);
}

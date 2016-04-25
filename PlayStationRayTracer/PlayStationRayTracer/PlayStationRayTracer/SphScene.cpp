#include "SphScene.h"


SphScene::SphScene()
{
	spheres = new std::vector<Sphere>();
}


SphScene::~SphScene()
{
}
void SphScene::AddSphere(
	const Vec3f &c,
	const float &r,
	const Vec3f &sc,
	const float &refl,
	const float &transp,
	const Vec3f &ec){

}
Sphere SphScene::getSphere(int num) const{
	return spheres->at(num);
}
bool SphScene::DoesSphereIntersect(int spherNum, const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const{
	return spheres->at(spherNum).intersect(rayorig, raydir, t0, t1);
}
Sphere* SphScene::getSphereRef(int num){
	return &spheres->at(num);
}
int SphScene::GetSize() const{
	spheres->size();
}
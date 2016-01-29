#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::SmoothScaling()
{
	Renderer rend;
	for (int r = 0; r <= 100; r++)
	{
		spheres.push_back(Sphere(Vec3f(0.0, -10004, -10), 10000, Vec3f(0.20f, 0.20f, 0.20f), 1, 0.0));
		spheres.push_back(Sphere(Vec3f(0.0, 0, -10), r / 100, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5)); // Radius++ change here
		spheres.push_back(Sphere(Vec3f(5.0, -1, -5), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0));
		spheres.push_back(Sphere(Vec3f(5.0, 0, -15), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0));
		rend.render(spheres, r, "help");
		std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
		// Dont forget to clear the Vector holding the spheres.
		spheres.clear();

	}
}

void Scene::Update()
{
}

void Scene::AddSphere(const Vec3f & c, const float & r, const Vec3f & sc, const float & refl, const float & transp, const Vec3f & ec)
{
	spheres.push_back(Sphere(c, r, sc, refl, transp, ec));
}

Sphere Scene::getSphere(int num) const
{
	return spheres[num];
}

int Scene::GetSize() const
{
	return spheres.size();
}

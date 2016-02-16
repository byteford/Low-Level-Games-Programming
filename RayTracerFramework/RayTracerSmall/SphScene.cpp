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
	Sphere temp(c, r, sc, refl, transp, ec);
	spheres->push_back(temp);
	std::cout << temp.ToString();
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
void SphScene::LoadSpheresFromFile(){
	std::stringstream fileLoc;
	fileLoc << "SceneIn/Scene.txt";
	std::string in;
	std::ifstream input(fileLoc.str().c_str(), std::ios::in);
	if (input.is_open()){
		while (std::getline(input, in)){
			//std::cout << in << "\n";
			if (in.at(0) == 's'){
				AddSphere(in);
			}
			else{
				std::cout << in << "\n";

			}
		}

	}
}
void SphScene::AddSphere(std::string str){
	std::cout << "init sphere " << str << "\n";
	std::string info;
	Vec3f pos;
	float rad;
	Vec3f surfaceCol;
	float reflect;
	float trans;
	Vec3f emission;

	std::size_t StartLoc;
	std::size_t endLoc;
	StartLoc = str.find(" ");
	endLoc = str.find(" ", StartLoc + 1); 
	info = str.substr(StartLoc + 1, (endLoc - 1));
	pos.x = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	pos.y = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	pos.z = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	rad = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	surfaceCol.x = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	surfaceCol.y = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	surfaceCol.z = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	reflect = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	trans = std::atoi(info.c_str());

	/*StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	emission.x = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	emission.y = std::atoi(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	emission.z = std::atoi(info.c_str());*/

	AddSphere(pos, rad, surfaceCol, reflect, trans);
	std::cout << emission << "\n";
}
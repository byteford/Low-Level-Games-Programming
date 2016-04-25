#include "SphScene.h"


SphScene::SphScene()
{
	spheres = new std::vector<Sphere>();
}


SphScene::~SphScene()
{
}
void SphScene::Update(int frameNum)
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
	return spheres->size();
}
void SphScene::LoadSpheresFromFile() {
	std::stringstream fileLoc;
	fileLoc << "SceneIn/Scene.txt";
	std::string in;
	std::ifstream input(fileLoc.str().c_str(), std::ios::in);
	if (input.is_open()) {
		while (std::getline(input, in)) {
			//std::cout << in << "\n";
			if (in.at(0) == 's') {
				AddSphere(in);
			}
			else if (in.at(0) == 'm') {
				LoadMove(in);
			}
			else {
				//std::cout << in << "\n";
				Logger::output(in);
				Logger::output("\n");
			}
		}

	}
}
void SphScene::AddSphere(std::string str) {
	//std::cout << "init sphere " << str << "\n";
	Logger::output("init sphere");
	Logger::output(str);
	Logger::output("\n");
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

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	if (endLoc > StartLoc) {
		info = str.substr(StartLoc + 1, (endLoc - 1));
		emission.x = std::atoi(info.c_str());

		StartLoc = endLoc;
		endLoc = str.find(" ", StartLoc + 1);
		info = str.substr(StartLoc + 1, (endLoc - 1));
		emission.y = std::atoi(info.c_str());

		StartLoc = endLoc;
		endLoc = str.find(" ", StartLoc + 1);
		info = str.substr(StartLoc + 1, (endLoc - 1));
		emission.z = std::atoi(info.c_str());
	}
	AddSphere(pos, rad, surfaceCol, reflect, trans, emission);
}

void SphScene::LoadMove(std::string str)
{
	int startFrame, endFrame, sphere;
	float x, y, z;
	std::string info;
	std::size_t StartLoc;
	std::size_t endLoc;

	StartLoc = str.find(" ");
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	startFrame = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	endFrame = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	sphere = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	x = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	y = std::stof(info.c_str());

	StartLoc = endLoc;
	endLoc = str.find(" ", StartLoc + 1);
	info = str.substr(StartLoc + 1, (endLoc - 1));
	z = std::stof(info.c_str());
	/*moves->push_back(MoveCom(startFrame, endFrame, sphere, x, y, z));
	std::stringstream* stream = new std::stringstream();
	*stream << startFrame << endFrame << sphere << x << y << z << "\n";
	Logger::output(stream);*/
}
#include "Texturepaths.h"
#include <unordered_map>
#include <string>
#include<vector>
namespace engine {
	std::unordered_map<std::string, std::vector<const char*>> Texturepaths::textures;
	Texturepaths::Texturepaths() {
		std::vector <const char*>obstacles;
		std::vector <const char*>characters;
		std::vector <const char*>background;
		textures = {
			std::make_pair("Obstacle", obstacles),
			std::make_pair("Characters", characters),
			std::make_pair("Background", background)
		};
	}
//	Texturepaths::~Texturepaths() {
//		delete an_instance;
//	}
}
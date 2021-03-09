#ifndef TEXTUREPATHS_H
#define TEXTUREPATHS_H
#include <unordered_map>
#include <string>
#include<vector>
namespace engine {
	class Texturepaths
	{
	private:
		static std::unordered_map<std::string, std::vector<const char*>> textures;   
		Texturepaths();
		static Texturepaths* an_instance;
	public:
		~Texturepaths();
		static Texturepaths* getInstance() {return an_instance = (an_instance != nullptr) ? an_instance : new Texturepaths();}
		static void addTexture(std::string type, const char* texturePath);
		static  std::vector<const char*>getTexture(std::string key) {return textures[key];};
		Texturepaths(const Texturepaths& c) = delete;
		const Texturepaths& operator= (const Texturepaths& t) = delete;
	};
}
#endif
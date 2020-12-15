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
		~Texturepaths();//needs implementaiton to remove pointer to instance
		static Texturepaths* getInstance() {
			return an_instance = (an_instance != nullptr) ? an_instance : new Texturepaths();
		}
		static void addTexture(std::string type, const char* texturePath) {
			std::vector<const char*> values = textures[type];
			values.push_back(texturePath);
			textures[type] = values;
		};
		static  std::vector<const char*>getTexture(std::string key) {
			return textures[key];
		};
	};
}
#endif
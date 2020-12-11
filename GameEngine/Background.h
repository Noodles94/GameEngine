#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Component.h"
#include "System.h"
#include <vector>

namespace engine {
	class Background : public Component
	{
	public:
		static Background* getInstance(const char* pathToTexture) {
			return new Background(pathToTexture);
		}
		void tick() override;
		void draw() const;
		void setBackgroundSet(const char* texturePaths[], int numAnimations);
	private:
		std::vector<SDL_Texture*> backgroundSet;
		Background(const char* pathToTexture);
		int animationTick = 0;
	};
}
#endif


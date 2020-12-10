#ifndef MAINCHARACTER_H
#define MAINCHARCATER_H
#include "Component.h"
#include <vector>

namespace engine {
	class MainCharacter : public Component
	{
	public:
		void spacebarEvent(const SDL_Event& event);
		 static MainCharacter* getInstance(int x, int y, int w, int h, const char* pathToTexture){
			return new MainCharacter(pathToTexture);
		}
		void tick()override;
		void setAnimationSet(const char* texturePaths[]);
	private:
		std::vector<SDL_Texture*> textureSet;
		MainCharacter(const char* pathToImage);
		// set speed of animation
		int animationTick = 0;
	};
}
#endif


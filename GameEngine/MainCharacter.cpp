#include "MainCharacter.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>
namespace engine {

	MainCharacter::MainCharacter(const char * pathToImg) 
		:Component(64, 64, 64, 64, pathToImg)
	{}

	void MainCharacter::tick() {
		int i = animationTick / 10;
		texture = textureSet[i];
		if (animationTick >= (textureSet.size()-1) * 10) {
			animationTick = 0;
		}
		else {
	animationTick += 1;
	}	
	}
	void MainCharacter::setAnimationSet(const char* texturePaths[])
	{
		//best solution
		for (int i = 0; i < 3; i++) {
			SDL_Texture*  textureTemp = IMG_LoadTexture(system.getMainRenderer(), texturePaths[i]);
			textureSet.push_back(textureTemp);
		}
		texturePaths = NULL;
	}
	void MainCharacter::spacebarEvent(const SDL_Event& event) {
		rectangle.y = rectangle.y + 10;
	}
}
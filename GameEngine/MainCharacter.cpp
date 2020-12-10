#include "MainCharacter.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h>
namespace engine {

	MainCharacter::MainCharacter(int x, int y, int w, int h, const char * pathToImg) 
		:Component(x, y, w, h, pathToImg)
	{}

	void MainCharacter::tick() {
		int animationSpeed = 40;
		int i = animationTick / animationSpeed;
		//sets new texture
		texture = textureSet[i];
		if (animationTick >= ((textureSet.size()-1) * animationSpeed) + (animationSpeed -1)) {
			animationTick = 0;
		}
		else{
		animationTick += 1;
		}
	}
	void MainCharacter::setAnimationSet(const char* texturePaths[], int numAnimations)
	{
		//Minnesläckage?? TexturePaths
		for (int i = 0; i < numAnimations; i++) {
			SDL_Texture*  textureTemp = IMG_LoadTexture(system.getMainRenderer(), texturePaths[i]);
			textureSet.push_back(textureTemp);
		}
	}
	void MainCharacter::spacebarEvent(const SDL_Event& event) {
		rectangle.y = rectangle.y + 10;
	}
}
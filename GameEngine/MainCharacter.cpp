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
		//jump
		bool ascend = true;
		if (rectangle.y == startPosY) {
			isJumping = true;
			ascend = true;
		}
		if (isJumping) {
			//ascend
			if ((rectangle.y >= rectangle.y + 50) && (rectangle.y == lastTickJump - 5) && ascend) {
				//Up 5 pixels per frame
				rectangle.y = rectangle.y - 5;
				lastTickJump = rectangle.y;
			}
			else if (rectangle.y == 50) {
				ascend = false;
			}
			else if (!ascend) {
				//Down 10 pixels per frame
				rectangle.y = rectangle.y + 10;
				if (rectangle.y == startPosY) {
					isJumping = false;
				}
			}
			
			//descend

		}

	}
}
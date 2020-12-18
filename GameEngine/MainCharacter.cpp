#include "MainCharacter.h"
#include <SDL.h>
#include "System.h"
#include <SDL_image.h> 
#include <iostream>
namespace engine {

	MainCharacter::MainCharacter(int x, int y, int w, int h, const char * pathToImg, int hitboxX, int hitboxY)
		:Component(x, y, w, h, pathToImg)
	{
		hitbox.w = hitboxX;
		hitbox.h = hitboxY;
		hitbox.x = x;
		hitbox.y = y;
	}

	void MainCharacter::tick() {
		int i = currentAnimationTick / animationSpeed;
		//sets new texture
		texture = textureSet[i];
		// if current Animation Tick Is one  lower than max reset the tick counter
		if (currentAnimationTick >= ((textureSet.size()-1) * animationSpeed) + (animationSpeed -1)) {
			currentAnimationTick = 0;
		}
		else{
			currentAnimationTick += 1;
		}
		//jumping
		if (isJumping && rectangle.y >= startPosY-110&& asending) {
			moveCharacter(0, -5);
		}
		else if(isJumping&&rectangle.y <= startPosY-5){
			asending = false;
			moveCharacter(0, 5);
		}
		else {
			asending = true;
			isJumping = false;
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
	const SDL_Rect* MainCharacter::getHitbox()
	{
		return  &hitbox;
	}
	void MainCharacter::moveCharacter(int x, int y)
	{
		rectangle.x = rectangle.x + x;
		rectangle.y = rectangle.y + y;
		hitbox.x = hitbox.x + x;
		hitbox.y = hitbox.y + y;
	}
	
	void MainCharacter::spacebarEvent(const SDL_Event& event) {
		isJumping = true;
	}
}
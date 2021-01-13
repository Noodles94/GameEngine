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
		//Change texture from existing list of textures for this object.
		texture = animationList[i];
		//If current Animation tick is one  lower than max reset the tick counter.
		//Changes the texture for maincharachter within a certain time frame.
		if (currentAnimationTick >= ((animationList.size() - 1) * animationSpeed) + (animationSpeed - 1)) {
			currentAnimationTick = 0;
		}
		else {
			currentAnimationTick += 1;
		}
		//Checks the state of jumping action. Then takes appropriet action. E.G falling, ascending. 
		if (isJumping && rectangle.y >= startPosY - 110 && isAscending) {
			moveCharacter(0, -5);
		}
		else if(isJumping && isAscending) {
			isAscending = false;
		}
		else if (!isAscending&&rectangle.y <= startPosY - 5) {
			moveCharacter(0, 5);
		}
		else {
			isJumping = false;
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

	void MainCharacter::setIsJumping(bool jumping, bool ascending)
	{
		isAscending = ascending;
		isJumping = jumping;
	}
	
	void MainCharacter::spacebarEvent(const SDL_Event& event) {
		if (!isJumping) {
			isJumping = true;
			isAscending = true;
		}
	}
}
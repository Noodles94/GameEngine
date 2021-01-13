#include "Background.h"
#include "System.h"
#include <SDL_image.h>
namespace engine {
	Background::Background(const char* pathToImg)
		:Component(0, 0, 800, 600, pathToImg)
	{
		system.getGameWindow();
	}

	void Background::draw() const {
		//Copy texture over entire screen
		SDL_RenderCopy(system.getMainRenderer(), texture, NULL, NULL);
	}

	void Background::tick() {
		int i = currentAnimationTick / animationSpeed;
		//sets new texture
		texture = animationList[i];
		if (currentAnimationTick >= ((animationList.size() - 1) * animationSpeed) + (animationSpeed - 1)) {
			currentAnimationTick = 0;
		}
		else {
			currentAnimationTick += 1;
		}
	}
}
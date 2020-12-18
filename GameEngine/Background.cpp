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
		//full window
		SDL_RenderCopy(system.getMainRenderer(), texture, NULL, NULL);
	}
	void Background::setBackgroundSet(const char* texturePaths[], int numAnimations)
	{
		for (int i = 0; i < numAnimations; i++) {
			SDL_Texture* textureTemp = IMG_LoadTexture(system.getMainRenderer(), texturePaths[i]);
			backgroundSet.push_back(textureTemp);
		}
	}
	//does nothing for backgroud
	void Background::spacebarEvent(const SDL_Event& event)
	{
	}
	void Background::tick() {
		int i = currentAnimationTick / animationSpeed;
		//sets new texture
		texture = backgroundSet[i];
		if (currentAnimationTick >= ((backgroundSet.size() - 1) * animationSpeed) + (animationSpeed - 1)) {
			currentAnimationTick = 0;
		}
		else {
			currentAnimationTick += 1;
		}
	}
}
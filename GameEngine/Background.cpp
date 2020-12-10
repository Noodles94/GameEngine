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
	void Background::setBakgroundSet(const char* texturePaths[], int numAnimations)
	{
		for (int i = 0; i < numAnimations; i++) {
			SDL_Texture* textureTemp = IMG_LoadTexture(system.getMainRenderer(), texturePaths[i]);
			bakgroundSet.push_back(textureTemp);
		}
	}
	void Background::tick() {
		int animationSpeed = 20;
		int i = animationTick / animationSpeed;
		//sets new texture
		texture = bakgroundSet[i];
		if (animationTick >= ((bakgroundSet.size() - 1) * animationSpeed) + (animationSpeed - 1)) {
			animationTick = 0;
		}
		else {
			animationTick += 1;
		}
	}
}
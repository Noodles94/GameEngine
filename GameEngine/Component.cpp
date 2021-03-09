#include "Component.h"
#include "System.h"
#include <SDL_image.h>
#include "GameLoop.h"
namespace engine {
	//Constructor
	Component::Component(int x, int y, int w, int h, const char* pathToTexture)
		:rectangle{ x, y, w, h }
	{ 
		texturePath = pathToTexture;
		texture = IMG_LoadTexture(system.getMainRenderer(), pathToTexture);
	}

	const SDL_Rect* Component::getRect() {
		return &rectangle;
	}

	//Draw the image
	void Component::draw() const {
		SDL_RenderCopy(system.getMainRenderer(), texture, NULL, &rectangle);
	}

	Component::~Component() {
		if(texture != nullptr)
			SDL_DestroyTexture(texture);
		for (auto i : animationList) {
			SDL_DestroyTexture(i);
		}
	}

	void Component::setAnimationSpeed(int speed)
	{
		animationSpeed = speed;
	}

	void Component::setAnimationList(const char* texturePaths[], int numAnimations)
	{
		for (int i = 0; i < numAnimations; i++) {
			SDL_Texture* textureTemp = IMG_LoadTexture(system.getMainRenderer(), texturePaths[i]);
			animationList.push_back(textureTemp);
		}
	}
}
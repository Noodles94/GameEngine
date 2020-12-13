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
		SDL_DestroyTexture(texture);
		//texture path minnesläckage?
	}
	void Component::spacebarEvent(const SDL_Event& event) {
		//Do something
	}
}
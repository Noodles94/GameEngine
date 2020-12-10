#include "Component.h"
#include "System.h"
#include <SDL_image.h>
#include "GameLoop.h"
namespace engine {

	//Constructor
	Component::Component(int x, int y, int w, int h, const char* pathToTexture)
		:rectangle{ x, y, w, h }
	{
		texture = IMG_LoadTexture(system.getMainRenderer(), pathToTexture);
	}
	//Draw the image
	void Component::draw() const {
		SDL_RenderCopy(system.getMainRenderer(), texture, NULL, &rectangle);
	}
	Component::~Component() {
		SDL_DestroyTexture(texture);
	}
	void Component::spacebarEvent(const SDL_Event& event) {
		//Do something
	}
}
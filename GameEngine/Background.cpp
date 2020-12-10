#include "Background.h"
#include "System.h"
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
	void Background::tick() {

	}
}
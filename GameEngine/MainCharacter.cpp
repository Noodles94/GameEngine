#include "MainCharacter.h"
namespace engine {

	MainCharacter::MainCharacter(const char * pathToImg) 
		:Component(64, 64, 64, 64, pathToImg)
	{}

	void MainCharacter::tick() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				//When X is pressed on the window;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_SPACE:
					//rocket science
					rectangle.y = rectangle.y + 10;
					break;
				}
				break;
			}
		}//inner WHILE
	}
}
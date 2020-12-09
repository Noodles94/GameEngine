#include "System.h"
#include <SDL.h>

namespace engine {
	System system;
	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		gameWindow = SDL_CreateWindow("Wheelrun", 100, 100, 800, 600, 0);
		mainRenderer = SDL_CreateRenderer(gameWindow, -1, 0);
	}
	System::~System() {
		SDL_DestroyWindow(gameWindow);
		SDL_DestroyRenderer(mainRenderer);
		SDL_Quit();

	}
	SDL_Renderer* System::getMainRenderer() const {
		return mainRenderer;
	}
	SDL_Window* System::getGameWindow() const {
		return gameWindow;
	}
}
#include "GameLoop.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
#define FPS 60 //Frames per Second
namespace engine {
	GameLoop game;
	GameLoop::GameLoop(){}
	GameLoop::~GameLoop()
	{
		for (int i = 0; i < currentComponents.size(); ++i) {
			delete currentComponents[i];
		}
	}
	void GameLoop::addComponent(Component* component) {
		currentComponents.push_back(component);
	}
	
	void GameLoop::loop() {
		//SDL_SetRenderDrawColor(system.getMainRenderer(),100, 100, 100, 100);
		const int tickInterval = 1000 / FPS;
		Uint32 nextTick;
		int delay;
		continueLoop = true;
		while (continueLoop) {
			nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					continueLoop = false;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_SPACE:
						for (auto i : currentComponents) {
							i->spacebarEvent(event);
						}
						break;
					}
					break;
				}
			}
			for (auto i : currentComponents) {
				i->tick();
			}
			SDL_RenderClear(system.getMainRenderer());
			addNewComponents();
			drawComponents();
			SDL_RenderPresent(system.getMainRenderer());
			delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		}//outer WHILE

	}
	void GameLoop::addNewComponents() {
		for (auto i : toAddComponents) {
			currentComponents.push_back(i);
		}
		toAddComponents.clear();
	}
	void GameLoop::drawComponents() {
		for (auto i : currentComponents) {
			i->draw();
		}
	}
}
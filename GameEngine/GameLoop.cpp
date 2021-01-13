#include "GameLoop.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
#include "MovingBlock.h"
#include "Texturepaths.h"
#define FPS 60 //Frames per Second
namespace engine {
	GameLoop game;
	GameLoop::~GameLoop()
	{
		for (int i = 0; i < currentComponents.size(); ++i) {
			delete currentComponents[i];
		}
		for (int i = 0; i < toRemoveComponents.size(); ++i) {
			delete toRemoveComponents[i];
		}
		for (int i = 0; i < toAddComponents.size(); ++i) {
			delete toAddComponents[i];
		}
	}

	void GameLoop::addComponent(Component* component) {
		currentComponents.push_back(component);
	}
	
	void GameLoop::loop() {
		const int tickInterval = 1000 / FPS;
		Uint32 nextTick;
		int delay;
		int points = 0;	//points for run 
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
				points += 1;
				i->tick();
			}
			addObstacles();
			SDL_RenderClear(system.getMainRenderer());
			addNewComponents();
			drawComponents();
			removeOldComponents();
			SDL_RenderPresent(system.getMainRenderer());
			delay = nextTick - SDL_GetTicks();
			if (delay > 0)
				SDL_Delay(delay);
		}
		removeAllComponents();
		std::cout << "Your score: "<< points;
	}

	void GameLoop::addNewComponents() {
		for (auto i : toAddComponents) {
			currentComponents.push_back(i);
		}
		toAddComponents.clear();
	}

	void GameLoop::removeOldComponents() {
		for (std::vector<Component*>::iterator i = currentComponents.begin(); i != currentComponents.end(); ++i) {
			for (Component* c : toRemoveComponents) {
				if (*i == c) {
					i = currentComponents.erase(i);
					delete c;
					--i;
					break;
				}
			}
		}
		toRemoveComponents.clear();
	}

	void GameLoop::drawComponents() {
		for (auto i : currentComponents) {
			i->draw();
		}
	}

	void GameLoop::addObstacles() {
		if (obstacleCreationCurrentTick >=(obstacleCreationSpeed -1)){
			std::vector <const char*>obstacleList = Texturepaths::getTexture("Obstacle");
			
			obstacleCreationCurrentTick = 0;
			MovingBlock* temp = MovingBlock::getInstance(obstacleList[rand() % obstacleList.size()],497  - rand() % 70);
			game.toAddComponents.push_back(temp);
			// makes obstacles create faster and faster until maxspeed
			if(obstacleCreationSpeed> minDistanceBeetweenObjects)
				obstacleCreationSpeed -= 1;
		}
		else {
			obstacleCreationCurrentTick += 1;
		}
	}

	void GameLoop::removeAllComponents() {
		for(int i = 0; i< currentComponents.size(); i++){
			delete currentComponents[i];
		}
		currentComponents.clear();
	}
}

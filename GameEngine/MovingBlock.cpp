#include "MovingBlock.h"
#include "GameLoop.h"
#include "MainCharacter.h"
#include "Component.h"
#include <SDL.h>
#include <vector>
#include <iostream>

namespace engine {
	//Constructor
	MovingBlock::MovingBlock(const char* pathToImage)
		:Component(800 - 32, blockHeight, 32, 32, pathToImage)
	{
	}
	MovingBlock* MovingBlock::getInstance(const char* pathToTexture)
	{
		return new MovingBlock(pathToTexture);;
	}
	//Destructor
	MovingBlock::~MovingBlock() {
		//ej minnesläckage
	}
	//Update
	void MovingBlock::tick() {
		rectangle.x = rectangle.x - 5;
		//if collission
		for (auto i : game.currentComponents) {
			if (MainCharacter* v = dynamic_cast<MainCharacter*>(i)) {
				if (SDL_HasIntersection(v->getHitbox(), getRect())) {
					//terminate game
					game.continueLoop = false;
				}
			}
		}
		//Destroy objects that goes out of window
		if (rectangle.x < 0 - 32 && alive) {
			alive = false;
			game.toRemoveComponents.push_back(this);
		}
		++dd;
		if (dd % 10 == 0 && alive) {
			std::cout << "living";
		}
	}
}
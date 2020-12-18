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

	//does nothing for moving block
	void MovingBlock::spacebarEvent(const SDL_Event& event) {};
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
					if (((v->getHitbox()->y + (v->getHitbox()->h/1.5)) >= (rectangle.y- rectangle.h/2)
						&& (v->getHitbox()->y + (v->getHitbox()->h) <= (rectangle.y+6)))) {
						if ((v->getHitbox()->x + (v->getHitbox()->w / 1.5)) <= (rectangle.x - rectangle.w / 2)) {
							v->setIsJumping(false,false);
						}
						else {
							v->setIsJumping(false,true);
							v->moveCharacter(0, -5);
						}
							
					}else {
						//terminate game
						game.continueLoop = false;
					}
				
				}
			}
		}
		//Destroy objects that goes out of window
		if (rectangle.x < 0 - 32 && alive) {
			alive = false;
			game.toRemoveComponents.push_back(this);
		}
		++dd;
		if (dd % 10 == 0) {
			std::cout << "living";
		}
	}
}
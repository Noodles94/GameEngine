#include "MovingBlock.h"
#include "GameLoop.h"
#include "MainCharacter.h"
#include "Component.h"
#include <SDL.h>
#include <vector>
#include <iostream>

namespace engine {
	//Constructor
	MovingBlock::MovingBlock(const char* pathToImage, int blockHeight)
		:Component(800 - 32, blockHeight, 32, 32, pathToImage)
	{
	}
	MovingBlock* MovingBlock::getInstance(const char* pathToTexture, int blockHeight)
	{
		return new MovingBlock(pathToTexture,  blockHeight);;
	}

	//does nothing for moving block
	void MovingBlock::spacebarEvent(const SDL_Event& event) {};
	//Destructor
	MovingBlock::~MovingBlock() {
		//ej minnesläckage
	}
	void MovingBlock::tick() {
		rectangle.x = rectangle.x - 5;
		for (auto i : game.currentComponents) {
			//if character
			if (MainCharacter* v = dynamic_cast<MainCharacter*>(i)) {
				//if charachter has an colltion with object
				if (SDL_HasIntersection(v->getHitbox(), getRect())) {		
					//if at the end of the box
					if ((v->getHitbox()->x + (v->getHitbox()->w/2 )) >= (rectangle.x + rectangle.w)) {
						//start falling
						v->setIsJumping(false, false);
					}  
					//if charachter lands on top of box
					else if (((v->getHitbox()->y + (v->getHitbox()->h)) >= (rectangle.y- rectangle.h)
						&& (v->getHitbox()->y + (v->getHitbox()->h) <= (rectangle.y+6)))) {
						
							//jumping = false, asending is true. This floats the character on its current hight by turning of gravity. 
							v->setIsJumping(false, true);							
					}else {
						//game over 
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
	}
}
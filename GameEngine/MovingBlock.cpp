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
			MovingBlock* temp = MovingBlock::getInstance(texturePath);
			game.toAddComponents.push_back(temp);
			first = false;
		//if collission
		for (auto i : game.currentComponents) {
			if (MainCharacter* v = dynamic_cast<MainCharacter*>(i)) {
				if (SDL_HasIntersection(v->getRect(), getRect())) {
					//terminate game
					game.continueLoop = false;
				}
			}
	}


	


		//if (asd) {
		//	MainCharacter* d = MainCharacter::getInstance(400, 530 - 64, 64, 64, "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp");
		//	game.addComponent(d);
		//	asd = false;
		//	MovingBlock* mb = MovingBlock::getInstance("C:/MasterMap/PixelArt/Obstacles/Cobblestone.bmp");
		//	game.addComponent(mb);
		//}
	}
}
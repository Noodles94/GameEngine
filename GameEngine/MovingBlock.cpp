#include "MovingBlock.h"
#include "GameLoop.h"
#include "MainCharacter.h"
namespace engine {

	//Constructor
	MovingBlock::MovingBlock(const char* pathToImage)
		:Component(800 - 32, blockHeight, 32, 32, pathToImage)
	{
	}
	//Destructor
	MovingBlock::~MovingBlock() {
		//ej minnesläckage
	}
	//Update
	void MovingBlock::tick() {
		rectangle.x = rectangle.x - 1;
		//if (asd) {
		//	MainCharacter* d = MainCharacter::getInstance(400, 530 - 64, 64, 64, "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp");
		//	game.addComponent(d);
		//	asd = false;
		//	MovingBlock* mb = MovingBlock::getInstance("C:/MasterMap/PixelArt/Obstacles/Cobblestone.bmp");
		//	game.addComponent(mb);
		//}
	}
}
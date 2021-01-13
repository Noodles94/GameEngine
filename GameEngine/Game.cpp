#include <SDL.h>
#include <SDL_ttf.h>
#include "System.h"
#include "GameLoop.h"
#include "Component.h"
#include "MainCharacter.h"
#include "Background.h"
#include "MovingBlock.h"
#include "Texturepaths.h"
using namespace engine;
int main(int argc, char* argv[]) {
	//Maincharacter
	MainCharacter* t = MainCharacter::getInstance(64, 530 - 64, 64, 64, "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp",60,60);
	const char* mainCharacterTextureAnimations[] = { 
		"C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp" ,
		"C:/MasterMap/PixelArt/Characters/ManInWheelchairForward(1).bmp",
		"C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp",
		"C:/MasterMap/PixelArt/Characters/ManInWheelchairBackward(1).bmp" };
	t->setAnimationList(mainCharacterTextureAnimations, 4);
	//Background
	Background* back = Background::getInstance("C:/MasterMap/PixelArt/Bakground/BakgroundBase(1).bmp" );
	const char* bakgroundTextureAnimations[] = {
		"C:/MasterMap/PixelArt/Background/BakgroundBase(1).bmp",
		"C:/MasterMap/PixelArt/Background/BakgroundBase(2).bmp",
		"C:/MasterMap/PixelArt/Background/BakgroundBase(3).bmp",
	};
	back->setAnimationSpeed(20);
	back->setAnimationList(bakgroundTextureAnimations, 3);
	//Obstacles
	MovingBlock* mb = MovingBlock::getInstance("C:/MasterMap/PixelArt/Obstacles/Cobblestone.bmp",497);
	Texturepaths::addTexture("Obstacle", "C:/MasterMap/PixelArt/Obstacles/Cobblestone.bmp");
	Texturepaths::addTexture("Obstacle", "C:/MasterMap/PixelArt/Obstacles/CobblestoneGrass.bmp");
	Texturepaths::addTexture("Obstacle", "C:/MasterMap/PixelArt/Obstacles/CobblestoneGrassAndTwigs.bmp");
	
	//Add to game loop
	game.addComponent(back);
	game.addComponent(mb);
	game.addComponent(t);
	game.loop(); 
	return 0;
}	
#include <SDL.h>
#include <SDL_ttf.h>
#include "System.h"
#include "GameLoop.h"
#include "Component.h"
#include "MainCharacter.h"

using namespace engine;
int main(int argc, char* argv[]) {
	GameLoop game;
	MainCharacter* t = MainCharacter::getInstance(64, 64, 64, 64, "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp");
	const char* mainCharacterTextureAnimations[4] = { "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp" ,
		"C:/MasterMap/PixelArt/Characters/ManInWheelchairForward.bmp",
		"C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp",
		"C:/MasterMap/PixelArt/Characters/ManInWheelchairBackward.bmp" };
	t->setAnimationSet(mainCharacterTextureAnimations, 4);
	game.addComponent(t);
	game.loop(); 
	return 0;
}
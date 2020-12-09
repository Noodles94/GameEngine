#include <SDL.h>
#include <SDL_ttf.h>
#include "System.h"
#include "GameLoop.h"
#include "Component.h"
#include "MainCharacter.h"

using namespace engine;
int main(int argc, char* argv[]) {
	GameLoop game;
	//Component* t = Component::getInstance(64, 64, 64, 64, "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp");
	Component * t = MainCharacter::getInstance( "C:/MasterMap/PixelArt/Characters/ManInWheelchair.bmp");
	game.addComponent(t);
	game.loop();
	return 0;
}
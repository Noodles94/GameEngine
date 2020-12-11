#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <vector>
#include "Component.h"
namespace engine {
	class GameLoop
	{
	public:
		//Constructor
		GameLoop();
		//Destructor
		~GameLoop();
		//GameLoop
		void loop();
		//AddComponentToGame
		void addComponent(Component* component);
	private:
		//The components that should be removed the next frame
		std::vector<Component*> toRemoveComponents;
		//The componenets that are currently in the game loop
		std::vector<Component*> currentComponents;
		//The components that should be added the next frame
		std::vector<Component*> toAddComponents;
		//Add new components to vector which is used in gameloop
		void addNewComponents();
		//Draws all components on the screen
		void drawComponents();

	};
	extern GameLoop game;
}

#endif // !1


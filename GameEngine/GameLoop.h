#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <vector>
#include "Component.h"
#include "Texturepaths.h"
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
		//The componenets that are currently in the game loop
		std::vector<Component*> currentComponents;
		bool continueLoop;
		//The components that should be added the next frame
		std::vector<Component*> toAddComponents;
		//The components that should be removed the next frame
		std::vector<Component*> toRemoveComponents;

	private:
		int minDistanceBeetweenObjects = 80;
		int obstacleCreationCurrentTick = 0;
		int obstacleCreationSpeed = 160;
		//Add new components to vector which is used in gameloop
		void addNewComponents();
		//Draws all components on the screen
		void drawComponents();
		//add obstacele to game
		void addObstacles();
		void removeAllComponents();
		//add more difficult obstacles
		void addObstaclesMoreDifficult();
		//remove old components in the next frame
		void removeOldComponents();
	};
	extern GameLoop game;
}

#endif // !1


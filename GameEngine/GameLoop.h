#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <vector>
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
	private:
		//The components that should be removed the next frame
		std::vector<Component*> toRemoveComponents;
		//The componenets that are currently in the game loop
		std::vector<Component*> currentComponents;
		//The components that should be added the next frame
		std::vector<Component*> toAddComponents;
	};
}

#endif // !1


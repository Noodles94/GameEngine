#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
namespace engine {
	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* getMainRenderer() const;
		SDL_Window* getGameWindow() const;
	private:
		SDL_Window* gameWindow;
		SDL_Renderer* mainRenderer;
	};
	extern System system;
}

#endif // !SYSTEM_H


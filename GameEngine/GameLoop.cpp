#include "GameLoop.h"
#include <SDL.h>


namespace engine {
	GameLoop::GameLoop(){}
	GameLoop::~GameLoop()
	{
		for (int i = 0; i < currentComponents.size(); ++i) {
			delete currentComponents[i];
		}
	}
	void loop() {
		//SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
		bool quit = false;
		while (!quit) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					for (Component* c : currentComponents) {
						c->mouseDown(event);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : components) {
						c->mouseUp(event);
					}
					break;
				case SDL_KEYDOWN:
					for (Component* c : components) {
						c->keyDown(event);
					}
					break;
				case SDL_KEYUP:
					for (Component* c : components) {
						c->keyUp(event);
					}
					break;
				}//switch
			}//inre
			/*for (std::vector<Component*>::iterator i = components.begin(); i != components.end();) {
				for (Component* c : removed) {
					if (*i == c) {
						i = components.erase(i);
						delete c;
					}
					else { ++i; }
				}
			}*/
			//removed.clear();
			SDL_RenderClear(sys.getRen());
			//for (Component* c : components) {
			//	c->draw();
			//}
			SDL_RenderPresent(sys.getRen());
		}//yttre
	}
}
#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <string>

namespace engine {
	class Component
	{
	public:
		//Fabric function which returns an object created on the stack
		//virtual Component* getInstance(int x, int y, int w, int h, const char* pathToTexture) = 0;
		virtual void spacebarEvent(const SDL_Event &event);
		virtual void draw() const;
		virtual void tick()= 0; 
		const SDL_Rect* getRect();
		//Destructor
		~Component();
	protected:
		Component(int x, int y, int w, int h, const char* pathToTexture);
		SDL_Rect rectangle;
		SDL_Texture* texture;
		const char* texturePath;
	private:
		
	};
}

#endif

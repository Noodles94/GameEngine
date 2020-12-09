#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <string>
namespace engine {
	class Component
	{
	public:
		//Fabric function which returns an object created on the stack
		virtual Component* getInstance(int x, int y, int w, int h, const char* pathToTexture);
		void draw() const;
		virtual void tick(); 
		//Destructor
		~Component();
	protected:
		Component(int x, int y, int w, int h, const char* pathToTexture);
		SDL_Rect rectangle;
	private:
		SDL_Texture* texture;
	};
}

#endif

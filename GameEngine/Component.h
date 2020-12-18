#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <string>
#include <vector>

namespace engine {
	class Component
	{
	public:
		//Fabric function which returns an object created on the stack
		//virtual Component* getInstance(int x, int y, int w, int h, const char* pathToTexture) = 0;
		virtual void spacebarEvent(const SDL_Event &event) = 0;
		virtual void draw() const;
		virtual void tick()= 0; 
		const SDL_Rect* getRect();
		//Destructor
		~Component();
		void setAnimationSpeed(int speed);
		void setAnimationList(const char* texturePaths[], int numAnimations);
	protected:
		Component(int x, int y, int w, int h, const char* pathToTexture);
		SDL_Rect rectangle;
		SDL_Texture* texture;
		const char* texturePath;
		//defult animation speed
		int animationSpeed = 40;
		int currentAnimationTick = 0;
		std::vector<SDL_Texture*> animationList;
	private:
		
	};
}

#endif

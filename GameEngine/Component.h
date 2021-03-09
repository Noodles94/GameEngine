#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <string>
#include <vector>

namespace engine {
	class Component
	{
	public:
		virtual void spacebarEvent(const SDL_Event &event) = 0;
		virtual void draw() const;
		virtual void tick()= 0; 
		const SDL_Rect* getRect();
		virtual ~Component();
		void setAnimationSpeed(int speed);
		void setAnimationList(const char* texturePaths[], int numAnimations);
	protected:
		Component(int x, int y, int w, int h, const char* pathToTexture);
		SDL_Rect rectangle;
		SDL_Texture* texture;
		const char* texturePath;
		int animationSpeed = 40;//default animation speed
		int currentAnimationTick = 0;
		std::vector<SDL_Texture*> animationList;
	private:
		Component(const Component& c) = delete;
		const Component& operator = (const Component& t) = delete;
	};
}

#endif

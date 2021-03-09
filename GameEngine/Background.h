#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Component.h"
#include "System.h"
#include <vector>
#include <iostream>
#include <memory>
#include <utility>
namespace engine {
	class Background : public Component
	{
	public:
		static Background* getInstance(const char* pathToTexture) {
			return new Background(pathToTexture);
		}
		
		void spacebarEvent(const SDL_Event& event){}
		void tick() override;
		void draw() const;
	private:
		Background(const char* pathToTexture);
		Background(const Background& c) = delete;
		const Background& operator= (const Background& t) = delete;
	};
}
#endif


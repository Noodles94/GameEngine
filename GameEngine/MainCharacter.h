#ifndef MAINCHARACTER_H
#define MAINCHARCATER_H
#include "Component.h"
#include <vector>

namespace engine {
	class MainCharacter : public Component
	{
	public:
		void spacebarEvent(const SDL_Event& event);
		 static MainCharacter* getInstance(int x, int y, int w, int h, const char* pathToTexture,int hitboxX, int hitboxY){
			return new MainCharacter(x, y, w, h, pathToTexture, hitboxX, hitboxY);
		}
		void tick()override;
		const SDL_Rect* getHitbox();
		void moveCharacter(int x, int y);
		void setIsJumping(bool jumping, bool ascending);
	private:
		SDL_Rect hitbox;
		MainCharacter(int x, int y, int w, int h, const char* pathToImage, int hitboxX, int hitboxY);
		// set speed of animation
		bool isJumping = false;
		int startPosY = rectangle.y;
		bool isAscending = false;
	};
}
#endif


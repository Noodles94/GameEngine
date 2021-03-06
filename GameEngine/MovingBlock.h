#ifndef MOVINGBLOCK_H
#define MOVINGBLOCK_H
#include "Component.h"
#include "GameLoop.h"
#include <vector>

namespace engine {
	class MovingBlock : public Component
	{
	public:
		void spacebarEvent(const SDL_Event& event) {};
		static MovingBlock* getInstance(const char* pathToTexture, int blockHeight);
		~MovingBlock(){};
		void tick()override;
	private:
		MovingBlock( const char* pathToImage, int blockHeight);
		MovingBlock(const MovingBlock& c) = delete;
		const MovingBlock& operator= (const MovingBlock& t) = delete;

	};
}
#endif


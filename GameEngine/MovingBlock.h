#ifndef MOVINGBLOCK_H
#define MOVINGBLOCK_H
#include "Component.h"
#include "GameLoop.h"
#include <vector>

namespace engine {
	class MovingBlock : public Component
	{
	public:
		static MovingBlock* getInstance(const char* pathToTexture);
		~MovingBlock();
		void tick()override;

	private:
		bool first = true;
		MovingBlock( const char* pathToImage);
		static const int blockHeight = 496; //ScreenHeight - Constant
		bool alive = true;
		int dd = 0;
	};
}
#endif


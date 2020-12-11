#ifndef MOVINGBLOCK_H
#define MOVINGBLOCK_H
#include "Component.h"
#include <vector>

namespace engine {
	class MovingBlock : public Component
	{
	public:
		static MovingBlock* getInstance( const char* pathToTexture) {
			return new MovingBlock(pathToTexture);
		}
		~MovingBlock();
		void tick()override;
	private:
		MovingBlock( const char* pathToImage);
		static const int blockHeight = 496; //ScreenHeight - Constant
		bool asd = true;
	};
}
#endif


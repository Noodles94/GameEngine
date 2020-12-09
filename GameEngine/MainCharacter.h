#ifndef MAINCHARACTER_H
#define MAINCHARCATER_H
#include "Component.h"

namespace engine {
	class MainCharacter : public Component
	{
	public:
		static MainCharacter* getInstance(const char * path) {
			return new MainCharacter(path);
		}
		void tick();
	private:
		MainCharacter(const char* pathToImage);
	};
}
#endif


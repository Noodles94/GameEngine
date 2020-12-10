#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Component.h"
#include "System.h"

namespace engine {
	class Background : public Component
	{
	public:
		static Background* getInstance(const char* pathToTexture) {
			return new Background(pathToTexture);
		}
		void tick() override;
		void draw() const;
	private:
		Background(const char* pathToTexture);
	};
}
#endif


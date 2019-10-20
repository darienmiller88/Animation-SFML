#pragma once
#include <SFML/Graphics.hpp>

class Animation{
	public:

		/**
		*@param textureFileName: The file name for the spritesheet
		*@param spriteTimeLength: Time in seconds a singe sprite will stay on the screen.
		*@param numSprites: vector detailing how many sprites are on the spritesheet horizontally (x), and vertically (y).
		*/
		Animation(const std::string &textureFileName, float spriteTimeLength, const sf::Vector2u& numSprites);
		void updateSprites(float deltaTime, const sf::Vector2f &direction = sf::Vector2f());
		void drawCurrentSprite(sf::RenderWindow &window);

	private:
		void scaleSpriteSheet(const sf::Vector2u &numSprites);
	private:
		sf::Texture spriteTexture;
		std::vector<sf::Sprite> spritesToAnimate;
		int currentFrame;
		float currentTime;
		sf::Clock clock;
		
		//Time in seconds a singe sprite will stay on the screen.
		const float SPRITE_LENGTH_TIME;
};
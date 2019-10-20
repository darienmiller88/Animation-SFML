#include "Animation.h"
#include <iostream>
#include "Random.h"

Animation::Animation(const std::string &textureFileName, float spriteTimeLength, const sf::Vector2u &numSprites) : 
SPRITE_LENGTH_TIME(spriteTimeLength), currentTime(0.f), currentFrame(0){

	if (!spriteTexture.loadFromFile(textureFileName)) {
		std::cout << "File: " << textureFileName << " cannot be opened. Exiting program\n";
		exit(1);
	}

	sf::Vector2u spriteSize;

	//On the sprite sheet image that was read into "spriteTexture", it is a numSprites.x by numSprites.y sheet, so to get the
	//length and width of each sprite, I have to divide the length and width of the sprite sheet by the number of sprites
	//on each dimension.
	spriteSize.x = spriteTexture.getSize().x / numSprites.x;
	spriteSize.y = spriteTexture.getSize().y / numSprites.y;

	std::cout << "x = " << spriteSize.x << " y = " << spriteSize.y << "\n";
	
	Random rand;
	float xPos = rand.getFloatInRange(0, 500);
	float yPos = rand.getFloatInRange(0, 500);
	for (int y = 0; y < numSprites.y; y++){
		for (int x = 0; x < numSprites.x; x++){

			//Using the sprite sheet, we will slice a rectangle into each of the sprites, and push it into the vector
			//of sprites, going row by row, left to right.
			spritesToAnimate.push_back(sf::Sprite(spriteTexture, sf::IntRect(spriteSize.x * x, 
				spriteSize.y * y, spriteSize.x, spriteSize.y)));
			spritesToAnimate.back().setPosition(300, 300);
		}
	}
}

void Animation::updateSprites(float deltaTime, const sf::Vector2f &direction){
	currentTime = clock.getElapsedTime().asSeconds();

	if (currentTime >= SPRITE_LENGTH_TIME) {
		currentTime -= SPRITE_LENGTH_TIME;
		clock.restart();
		if (++currentFrame >= spritesToAnimate.size())
			currentFrame = 0;
	}

	for (auto& sprite : spritesToAnimate)
		sprite.move(direction);
	//spritesToAnimate[currentFrame].move(direction);
}

void Animation::drawCurrentSprite(sf::RenderWindow &window){
	window.draw(spritesToAnimate[currentFrame]);
}

void Animation::scaleSpriteSheet(const sf::Vector2u &numSprites){
	if (spriteTexture.getSize().x % numSprites.x != 0 or spriteTexture.getSize().y % numSprites.y != 0) {
		
		//If the width and height of the sprite sheet aren't perfectly disivible the number of sprites, cast the result
		//to an int, and multiply the result by the number of sprites. This will give us the exact window width and
		//height needed to resize the spritesheet to allow it to be divisible by the number of sprites.
		int newSpriteSheetWidth =  (spriteTexture.getSize().x / numSprites.x) * numSprites.x;
		int newSpriteSheetHeight = (spriteTexture.getSize().y / numSprites.y) * numSprites.y;

		float xScale = newSpriteSheetWidth  / spriteTexture.getSize().x;
		float yScale = newSpriteSheetHeight / spriteTexture.getSize().y;

		
	}
	
}

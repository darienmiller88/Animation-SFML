#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Random.h"
using namespace sf;

struct Asteroid {
	Asteroid(Animation anim, const Vector2f &position, const Vector2f &velocity) : asteroid(anim), position(position), 
	velocity(velocity) {

	}

	Animation asteroid;
	Vector2f position;
	Vector2f velocity;
};

int main() {
	RenderWindow window(sf::VideoMode(600, 600), "problem.exe", sf::Style::Close | sf::Style::Titlebar);

	Animation explosion("images/asteroid_4.png", 3 / 60.f, { 6, 5 });

	Animation explosions[]{
		Animation("images/asteroid_4.png", 3 / 60.f, { 6, 5 }),
		Animation("images/asteroid_4.png", 3 / 60.f, { 6, 5 }),
		Animation("images/asteroid_4.png", 3 / 60.f, { 6, 5 }),
		Animation("images/asteroid_4.png", 3 / 60.f, { 6, 5 }),
		Animation("images/asteroid_4.png", 3 / 60.f, { 6, 5 })
	};

	std::vector<Asteroid> asteroids;

	Random rand;
	for (size_t i = 0; i < 10; i++){
		asteroids.push_back(Asteroid(explosion, { 300, 300 }, { rand.getFloatInRange(-1.f, 1.f), rand.getFloatInRange(-1.f, 1.f) }));
	}


	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}


		window.clear(Color::Black);

		explosion.drawCurrentSprite(window);
		explosion.updateSprites(0, { 0.2, 0.2 });

		/*for (size_t i = 0; i < 5; i++)
		{
			explosions[i].drawCurrentSprite(window);
			explosions[i].updateSprites(0);
		}*/
		
		window.display();
	}
}
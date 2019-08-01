

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "textbox.hpp"
#include "player.hpp"
#include "fighter.hpp"
#include "enemy.hpp"

int overworld(sf::RenderWindow& window, int location);
void fighting(sf::RenderWindow& window);

float SCALE = 1;
const int WINDOW_WIDTH = int(64 * 15 * SCALE);
const int WINDOW_HEIGHT = int(64 * 11 * SCALE);
const int TILE_WIDTH = WINDOW_WIDTH / 64;
const int TILE_HEIGHT = WINDOW_HEIGHT / 64;
const int RESOLUTION = int(64 * SCALE);

int main()
{
	
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML window");
	window.setFramerateLimit(60);

	// Set the Icon
	sf::Image icon;
	if (!icon.loadFromFile(resourcePath() + "PlayerStandIn.png")) {
		return EXIT_FAILURE;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	int location = 1;
	while (location != 0) {
		location = overworld(window, location);
	}

	return EXIT_SUCCESS;
}

int overworld(sf::RenderWindow& window, int location)
{
	std::vector< std::vector<int> > spritemap(TILE_WIDTH, std::vector<int>(TILE_HEIGHT));

	// Load background for map
	sf::Texture maptexture;
	if (!maptexture.loadFromFile(resourcePath() + "vertsea.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite background(maptexture);
	float a = SCALE * (13 * .5 / 3);
	background.scale(a, a);

	// Create a graphical text to display


	sf::RectangleShape textboxbackground;
	textboxbackground.setFillColor(sf::Color::Black);
	sf::Vector2f textboxsize;
	textboxsize.x = WINDOW_WIDTH;
	textboxsize.y = 2 * RESOLUTION;
	textboxbackground.setSize(textboxsize);
	textboxbackground.setPosition(0, (TILE_HEIGHT - 2) * RESOLUTION);

	/*sf::Text text("Cannot enter buildings yet. Working on it.", font, RESOLUTION/2);
	text.setFillColor(sf::Color::White);
	text.setPosition(2*RESOLUTION, (TILE_HEIGHT - 2)*RESOLUTION);*/


	textbox text(TILE_WIDTH, TILE_HEIGHT, RESOLUTION);

	sf::Vector2f trigger(3 * RESOLUTION, 3 * RESOLUTION);

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
		return EXIT_FAILURE;
	}

	// Create the Player Character
	player one(WINDOW_WIDTH, WINDOW_HEIGHT, 3, 6);

	//create npc
	player npc(WINDOW_WIDTH, WINDOW_HEIGHT, 5, 5);


	//text.setHeadSprite(one.getheadsprite());
	// Play the music
	//music.play();

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}

			//Basic character movement from WASD
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {

				one.move(0, -1);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
				one.move(0, 1);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
				one.move(-1, 0);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
				one.move(1, 0);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
				//one.talk(&text1, &spritemap);
				one.enterFight();
			}
		}

		// Clear screen
		window.clear();

		// Draw the background
		window.draw(background);

		for (int y = 0; y < TILE_HEIGHT; y++) {
			for (int x = 0; x < TILE_WIDTH; x++) {
				//if (spritemap[x][y] == 1) {
					one.draw(window);
				//}
			}
		}

		// Draw the string
		//If location of player is (3,3), draw the string, with a textbox behind it.
		if (spritemap[3][3] == 1) {
			text.makeVisible();
		}
		else {
			if (text.isVisible())
			{
				text.makeInvisible();
			}
		}

		if (spritemap[13][7] == 1 && one.isReady()) {
			one.exitFight();
			fighting(window);
		}

		text.draw(window);

		// Update the window
		window.display();
	}

	return 0;
}

void fighting(sf::RenderWindow& window) {
	sf::Clock clock;

	sf::Texture maptexture;
	//if (!maptexture.loadFromFile(resourcePath() + "cute_image.jpg")) {
	//	return EXIT_FAILURE;
	//}
	maptexture.loadFromFile(resourcePath() + "cute_image.jpg");
	sf::Sprite background(maptexture);
	float a = SCALE * (13 * .5 / 3);
	background.scale(a, a);

	fighter one(WINDOW_WIDTH, WINDOW_HEIGHT, sf::Mouse::getPosition(window));
	enemy two(WINDOW_WIDTH, WINDOW_HEIGHT);


	while (window.isOpen())
	{
		float elapsedTime = clock.restart().asSeconds();
		one.update(elapsedTime);
		two.update(elapsedTime);

		// Process events
		sf::Event event;

		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}

			//Basic character movement from A,D,Space
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
				one.walk(-1);
				one.setDirection(left);
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::A) {
				one.slowing();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
				one.walk(1);
				one.setDirection(right);
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
				one.slowing();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				one.jump();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
				one.setDirection(up);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
				one.setDirection(down);
			}

			//Aiming triggers on left click, mouse movement or J
			if ((event.type == sf::Event::MouseMoved) ||
				(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::J)) {
				one.aim(sf::Mouse::getPosition(window));
			}

			//Can shoot with J or left mouse click
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::J) ||
				(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)) {
				one.shoot();
			}

			//Can slash with K or right mouse click
			if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::K) ||
				(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)) {
				one.slash();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::LShift) {
				return;
			}
		}


		// Clear screen
		window.clear();

		// Draw the background
		window.draw(background);

		one.draw(window);
		two.draw(window);


		// Update the window
		window.display();
	}

}

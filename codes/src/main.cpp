#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<Windows.h>
#include "Snake.h"
#include "Food.h"

#define WIDTH 80
#define HEIGHT 50
#define SIZE 15
#define W SIZE*WIDTH
#define H SIZE*HEIGHT
using namespace sf;

Snake snake({ WIDTH / 2,HEIGHT / 2 });
Food food;
int main() {
	Clock clock;
	float timer = 0, delay = 0.1;
	RenderWindow window(VideoMode(W, H), "Snake Game");
	Texture t1, t2,t3;
	t1.loadFromFile("images/green.bmp");
	t2.loadFromFile("images/blue.bmp");
	t3.loadFromFile("images/red.bmp");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);
	while (window.isOpen()) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
			snake.setDir('l');
		if (Keyboard::isKeyPressed(Keyboard::Right))
			snake.setDir('r');
		if (Keyboard::isKeyPressed(Keyboard::Up))
			snake.setDir('u');
		if (Keyboard::isKeyPressed(Keyboard::Down))
			snake.setDir('d');

		if (timer > delay) {
			snake.moveSnake();
			timer = 0;
			if (snake.eaten(food)) {
				snake.grow();
				food.genFood();
			}
		}
		if (snake.collided()) {
			window.clear();
			Text t;
			t.setString("Game Over ");
			Font f;
			if (!f.loadFromFile("fonts/arial.ttf"))
				std::cout << "Unable to Load Font ";
			t.setFont(f);
			t.setCharacterSize(40);
			t.setStyle(Text::Bold);
			t.setPosition(W / 2, H / 2);
			for (int i = 0; i < WIDTH; i++) {
				for (int j = 0; j < HEIGHT; j++) {
					sprite1.setPosition(i * SIZE, j * SIZE);
					window.draw(sprite1);
				}
			}
			window.draw(t);
			window.display();
			Sleep(3000);
			break;
		}
		//window.display();
		//window.clear();
		
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				sprite1.setPosition(i * SIZE, j * SIZE);
				window.draw(sprite1);
			}
		}
		std::vector<COORD> snakeBody = snake.getSnakeBody();
		for (int i = 0; i < snakeBody.size(); i++) {
			sprite2.setPosition(snakeBody[i].X * SIZE, snakeBody[i].Y * SIZE);
			window.draw(sprite2);
		}
		sprite3.setPosition(food.getFoodPos().X*SIZE, food.getFoodPos().Y*SIZE);
		window.draw(sprite3);
		window.display();
		
	}
}

#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>
#include "Food.h"
#include<vector>
class Snake {
	COORD pos;
	int len;
	int dir;
	std::vector<COORD> snakeBody;
public:
	Snake(COORD pos);
	COORD getPos();
	void setDir(int d);
	void moveSnake();
	bool collided();
	bool eaten(Food& food);
	void grow();
	std::vector<COORD> getSnakeBody();
};

#endif
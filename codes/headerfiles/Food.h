#ifndef FOOD_H
#define FOOD_H
#include<windows.h>
class Food
{
	COORD foodPos;
public:
	Food();
	void genFood();
	COORD getFoodPos();
};

#endif
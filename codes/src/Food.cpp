#include "Food.h"
#include<ctime>
#define WIDTH 80
#define HEIGHT 50
Food::Food() {
	srand(time(NULL));
	genFood();
}
void Food::genFood() {
	foodPos.X = rand() % WIDTH + 1;
	foodPos.Y = rand() % HEIGHT + 1;
}
COORD Food::getFoodPos() {
	return foodPos;
}

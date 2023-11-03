#include "number.h"

Number:: Number(int value, int xGrid, int yGrid)
{
	sizeX = 128;
	sizeY = 128;
	x = xGrid*sizeX+(xGrid+1)*8;
	y = yGrid * sizeY + (yGrid + 1) * 8;
	this->value = value;
	position.push_back(xGrid);
	position.push_back(yGrid);
}

//destruction d'un Number
Number:: ~Number()
{
}

#include "PositionDistance.h"

PositionDistance::PositionDistance(int x, int y, int distance)
{
	this->x = x;
	this->y = y;
	this->distance = distance;
}

PositionDistance::PositionDistance()
{
	x = 0;
	y = 0;
	distance = 0;
}

int PositionDistance::getX() {
   return x;
}

int PositionDistance::getY() {
   return y;
}

int PositionDistance::getDistance() {
   return distance;
}

bool PositionDistance::EqualsCoordinates(PositionDistance pd) {
	if (x == pd.x && y == pd.y && distance == pd.distance)
		return true;

	return false;
}




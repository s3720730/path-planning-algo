
#include "PathPlanning.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

PathPlanning::PathPlanning(Grid maze, int rows, int cols) {

	this->maze = maze;
	this->rows = rows;
	this->cols = cols;
	this->reachable = new PDList();
	this->temp_list = new PDList();
	
}

PathPlanning::~PathPlanning() {

	delete initial_position;
	initial_position = NULL;

	reachable->clear();
	reachable = NULL;

	reachableCpy->clear();
	reachableCpy = NULL;

	temp_list->clear();
	temp_list = NULL;
}

void PathPlanning::initialPosition(int x, int y) {

	this->initial_position = new PositionDistance(x, y, 0);
	reachable->addBack(initial_position);

}

PDList* PathPlanning::getReachablePositions() {

	PDPtr position = NULL;
	PDPtr temp_position = NULL;
	bool loop = true;
	int counter = 0;
	
	//loop to find all reachable positions
		while (loop) {
 
			// ends loop when temp_list has same elements as reachable due to all positions matching
			if (counter == (reachable->size())) {

			loop = false;
			
			}
			// checks for non-matching positions
			else if (temp_list->containsCoordinate(reachable->get(counter)) == false) {

				position = reachable->get(counter);	
				temp_list->addBack(position);
				counter = 0;

				for (int i = 0; i < 4; i++) {

					//for each iteration a different position is checked
					switch (i) {
						case 0:
							temp_position = new PositionDistance(position->getX() + 1, position->getY(), position->getDistance() + 1);
							break;
						case 1:
							temp_position = new PositionDistance(position->getX(), position->getY() + 1, position->getDistance() + 1);
							break;
						case 2:
							temp_position = new PositionDistance(position->getX() - 1, position->getY(), position->getDistance() + 1);
							break;
						case 3:
							temp_position = new PositionDistance(position->getX(), position->getY() - 1, position->getDistance() + 1);
							break;
					}

					//checks if the position is on a valid spot and checks if the position has already been added
					if (this->ValidPosition(temp_position) && (!reachable->containsCoordinate(temp_position))) {
						reachable->addBack(temp_position);
					}
					else {
						delete[] temp_position;
					}

				}

			}
			
			counter++;

		}

	//making copy of reachable array
	reachableCpy = this->makeCopy(reachable);

	//deletes initial position from reachable array
	reachableCpy->deleteItem(0);

   return reachableCpy;
}


bool PathPlanning::ValidPosition(PDPtr position) {
	if (this->maze[position->getY()][position->getX()] == '.')
		return true;

	return false;
}


// THIS IS FOR MILESTONE 3 ONLY
//    ONLY IMPLEMENT THIS IF YOU ATTEMPT MILESTONE 3
PDList* PathPlanning::getPath(int toX, int toY) {


	PDList* reachable_2 = new PDList();

	reachable_2->addBack(initial_position);

	Path pathFinder[100];
	pathFinder[0] = { new PDList(), initial_position };
	pathFinder[0].path->addBack(initial_position);
	num_of_paths = 1;

	int j = 0;

	PDList* temp_list_2 = new PDList();
	PDPtr temp_position = new PositionDistance();
	PDPtr position = new PositionDistance();

	bool loop = true;
	int counter = 0;

	while (loop) {
	
		if (counter == (reachable->size())) {
			
			loop = false;

		}
		else if (temp_list_2->containsCoordinate(reachable_2->get(counter)) == false) {
	
			position = reachable_2->get(counter);

			temp_list_2->addBack(position);

			counter = 0;
			int x = position->getX();
			int y = position->getY();
			int dis = position->getDistance();

			for (int i = 0; i < 4; i++) {

				switch (i) {
				case 0:
					temp_position = new PositionDistance(x + 1, y, dis + 1);
					break;
				case 1:
					temp_position = new PositionDistance(x, y + 1, dis + 1);
					break;
				case 2:
					temp_position = new PositionDistance(x - 1, y, dis + 1);
					break;
				case 3:
					temp_position = new PositionDistance(x, y - 1, dis + 1);
					break; 
				}

				//checks if coordinate is in reachable array and not in temp array
				if ((reachable->containsCoordinate(temp_position)) && (!reachable_2->containsCoordinate(temp_position))) {
									
					
					while (j < num_of_paths) {

						if (pathFinder[j].lastPosition->EqualsCoordinates(*position)) {

							pathFinder[num_of_paths].path = this->makeCopy(pathFinder[j].path);
							pathFinder[num_of_paths].path->addBack(temp_position);
							pathFinder[num_of_paths].lastPosition = temp_position;

							if (temp_position->getX() == toX && temp_position->getY() == toY) {
								return pathFinder[num_of_paths].path;
								
							}
							num_of_paths++;
							j = num_of_paths;


						}
						else {
							j++;
						}
					
					}
					j = 0;			
					reachable_2->addBack(new PositionDistance(temp_position->getX(), temp_position->getY(), temp_position->getDistance()));

				}
				else {

				}
	
				delete temp_position;
				temp_position = NULL;

			}
			
		}
		counter++;

		delete position;
		position = NULL;

	}
	return NULL;

}


PDPtr PathPlanning::getFinalPosition(Path p) {
	return p.lastPosition;
}


PDList* PathPlanning::makeCopy(PDList* list) {

	PDList* Copy = new PDList();
	for (int x = 0; x < list->size(); x++) {
		Copy->addBack(list->get(x));
	}

	return Copy;

}

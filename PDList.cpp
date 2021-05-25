
#include "PDList.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

PDList::PDList() {
	numPositions = 0;
}

PDList::~PDList() {
}

int PDList::size() {
   return numPositions;
}

PDPtr PDList::get(int i) {
   return positions[i];
}

void PDList::addBack(PDPtr position) {

	positions[numPositions] = position;
	numPositions++;

}

bool PDList::containsCoordinate(PDPtr position) {

	for (int x = 0; x < numPositions; x++) {
		if ((positions[x]->getX() == position->getX()) && (positions[x]->getY() == position->getY())) {
			return true;
		}
	}
   return false;
}

void PDList::clear() {

	for (int x = 0; x < numPositions; x++) {

		delete[] positions[x];
		positions[x] = NULL;

	}

	numPositions = 0;

}

void PDList::deleteItem(int i) {
	
	numPositions--;
	delete positions[i];
	for (int x = i; x < numPositions; x++) {

		positions[x] = positions[x + 1];

	}
	positions[numPositions] = NULL;

}


void PDList::printPDList() {

	for (int x = 0; x < numPositions; x++) {

		std::cout << "pos " << x << " : x=" << positions[x]->getX() << ", y=" << positions[x]->getY() << ", dis= " << positions[x]->getDistance() << std::endl;

	}
}

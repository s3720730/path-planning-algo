
#ifndef COSC_ASS_ONE_PATH_PLANNING
#define COSC_ASS_ONE_PATH_PLANNING

#include "PositionDistance.h"
#include "PDList.h"
#include "Types.h"

class PathPlanning {

	typedef struct Path {
		PDList* path;
		PDPtr lastPosition;
	}Path;

public:

   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */


   // Initialise a with a given maze of size (x,y)
   PathPlanning(Grid maze, int rows, int cols);

   // Clean-up
   ~PathPlanning();

   // The initial position
   void initialPosition(int x, int y);

   // Method for Milestone 2
   // Return a DEEP COPY of the PDList of all position-distance's
   //    that the robot can reach
   PDList* getReachablePositions();


   // Method for Milestone 3
   // Get the path from the starting position to the given co-ordinate
   //    The path should be a DEEP COPY
   PDList* getPath(int toX, int toY);

   /*                                           */
   /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
   /*                                           */

   bool ValidPosition(PDPtr position);

   PDList* makeCopy(PDList* list);

   PDPtr getFinalPosition(Path p);


private:

	Grid maze;
	int rows;
	int cols;
	PDPtr initial_position;
	PDList* reachable;
	PDList* reachableCpy;
	PDList* temp_list;
	int num_of_paths;

};


#endif // COSC_ASS_ONE_PATH_PLANNING

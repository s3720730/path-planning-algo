
#ifndef COSC_ASS_ONE_POSITION
#define COSC_ASS_ONE_POSITION

#include "Types.h"

class PositionDistance {
public:

   /*                                           */
   /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
   /*                                           */

   // x-co-ordinate
   int getX();

   // y-co-ordinate
   int getY();

   // Distance
   int getDistance();

   bool EqualsCoordinates(PositionDistance pd);


   /*                                           */
   /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
   /*                                           */
 

   PositionDistance(int x, int y, int distance);

   PositionDistance();

private:

	int x;
	int y;
	int distance;


};

/*                                           */
/* DO NOT MOFIFY THIS TYPEDEF                */
/*                                           */
// Pointer to a Position-Distance
typedef PositionDistance* PDPtr;

#endif // COSC_ASS_ONE_POSITION

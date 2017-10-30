#ifndef ANIMALS_H
#define ANIMALS_H

int typeOfMoveHare( const int typeOfMove );
int typeOfMoveTurtle( const int typeOfMove );
void moveHare( int * position, const int typeOfMove, const int trackLength );
void moveTurtle( int * position, const int typeOfMove, const int trackLength );

#endif

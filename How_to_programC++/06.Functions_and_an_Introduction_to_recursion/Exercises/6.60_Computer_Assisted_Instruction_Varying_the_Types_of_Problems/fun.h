// fun.h
#ifndef FUN_H
#define FUN_H
void displayMessage( int, int, int type=3 );		// display message for calculating result with operator
void displayAfterWrongAnswer();   					// print message for wrong answer
void displayAfterCorrectAnswer(); 					// print messsage for correct answer
void statistics( int countAll, int countCorrect );	// display statistics
int	 levelOfDifficulty(); 							// level of difficulty of mathematical tasks: 1(default) to 5
int  readArithmetic(); 	  							// display message on arithmetic options, and user input
int  typeOfArithmetic( int type=3 );				// four types of arithmetics
long long resultOfArithmetic( long long, long long, int type=3 ); // calculationing result with arithmetic type
#endif

// fun.h
#ifndef FUN_H
#define FUN_H
int levelOfDifficulty();			// level of difficulty of mathematical tasks: 1(default) to 5
void displayMessage( int, int );	// display message for calculating result
void displayAfterWrongAnswer(); 	// print message for wrong answer
void displayAfterCorrectAnswer();	// print messsage for correct answer
void statistics( int countAll, int countCorrect ); // display statistics
#endif

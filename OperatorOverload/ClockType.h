//ClockType.h
//#include "ClockType.h" to use the functionality of this class in your program.
#pragma once
class ClockType{
public:
	//This function takes three integers and sets the time of the clock in the order hr, min, and sec.
	//NOTE: This class automatically adjusts invalid or overflowing time values to the 24-hr time format.
	// i.e Overflow in seconds or minutes is carried over, and hours wrap around using 24-hour format.
	// For example, 78 seconds becomes 1 minute 18 seconds, and 34:45:92 becomes 10:46:32
	void setTime(int, int, int);

	//This function prints the time of the clock in the order hr:min:sec with leading zeros.
	void printTime() const;

	//This function overloads the equality operator (==) for ClockType data.
	bool operator== (const ClockType&) const;

	//This function overloads the greater than or equal to operator (>=) for ClockType data.
	bool operator>= (const ClockType& otherClock) const;

	//This function overloads the less than or equal to operator (<=) for ClockType data.
	bool operator<= (const ClockType& otherClock) const;

	//This function overloads the addition operator for ClockType data.
	//Values that exceed it's usual range is adjusted using the logic function.
	ClockType operator+ (const ClockType&) const;

	//This function overloads the subtraction operator for ClockType data.
	// Subtraction assumes the first time is greater than or equal to the second.
	// If the first time is smaller, results may be negative or invalid because borrowing occurs for minutes 
	// and seconds.
	ClockType operator- (const ClockType& otherClock) const;

	//This function overloads the multiplication operator for ClockType data.
	//Each value (hr, min and sec) are multiplied by a constant integer value.
	//Every value that exceeds it's usual range is adjusted using the logic function.
	ClockType operator* (int constant) const;
	
	//Adjusts hours, minutes, seconds to standard 24-hour time, carrying over as needed
	void logic();

	//This is the default constructor, it initialises each of hr, min, and sec to 0.
	ClockType();

	//This is a constructor, it takes in 3 integers in the order of hr, min, and sec and
	//sets the value when declared
	ClockType(int, int, int);

private:
	int hr;
	int min;
	int sec;
};

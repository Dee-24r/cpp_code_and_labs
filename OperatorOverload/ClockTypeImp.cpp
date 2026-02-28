//This is the implementation file for ClockType.h. Our client will not see this file.
//It contains all the function definitions for the class clockType
#include <iostream>
#include "ClockType.h"

using namespace std;

//This function takes three integers and sets the time of the clock in the order hr, min, and sec.
//NOTE: This class automatically adjusts invalid or overflowing time values to the 24-hr time format.
// i.e Overflow in seconds or minutes is carried over, and hours wrap around using 24-hour format.
// For example, 78 seconds becomes 1 minute 18 seconds, and 34:45:92 becomes 10:46:32
void ClockType::setTime(int hours, int minutes, int seconds) {
	hr = hours;
	min = minutes;
	sec = seconds;
	logic();
}

//This function prints the time of the clock in the order hr:min:sec with leading zeros.
void ClockType::printTime() const{
	if (hr < 10)
		cout << "0";

	cout << hr << ":";

		if (min < 10)
			cout << "0";

	cout << min << ":";

		if (sec < 10)
			cout << "0";

	cout << sec << " ";
}

//This function overloads the equality operator (==) for ClockType data.
bool ClockType::operator== (const ClockType& otherClock) const {
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

//This function overloads the greater than or equal to operator (>=) for ClockType data.
bool ClockType::operator>= (const ClockType& otherClock) const {
	if (hr != otherClock.hr)
		return (hr > otherClock.hr);

	if (min != otherClock.min)
		return (min > otherClock.min);

		return (sec >= otherClock.sec);
}

//This function overloads the less than or equal to operator (<=) for ClockType data.
bool ClockType::operator<= (const ClockType& otherClock) const {
	if (hr != otherClock.hr)
		return (hr < otherClock.hr);

	if (min != otherClock.min)
		return (min < otherClock.min);

	return (sec <= otherClock.sec);
}

//This function overloads the addition operator for ClockType data.
//Values that exceed it's usual range is adjusted using the logic function.
ClockType ClockType::operator+ (const ClockType& otherClock) const {
	ClockType clockSum(hr + otherClock.hr, min + otherClock.min, sec + otherClock.sec);

	clockSum.logic();
	return clockSum;
}

//This function overloads the subtraction operator for ClockType data.
// Subtraction assumes the first time is greater than or equal to the second.
// If the first time is smaller, results may be negative or invalid because borrowing occurs for minutes 
// and seconds.
ClockType ClockType::operator- (const ClockType& otherClock) const{

	int newSec = sec, newMin = min, newHr = hr;

	if (newSec < otherClock.sec) {
		newMin--;
		newSec += 60;
	}
	newSec -= otherClock.sec;

	if (newMin < otherClock.min) {
		newHr--;
		newMin += 60;
	}
	newMin -= otherClock.min;

	newHr -= otherClock.hr;

	ClockType clockDiff(newHr, newMin, newSec);
	return clockDiff;
}

//This function overloads the multiplication operator for ClockType data.
//Each value (hr, min and sec) are multiplied by a constant integer value.
//Every value that exceeds it's usual range is adjusted using the logic function.
ClockType ClockType::operator* (int constant) const {
	ClockType clockProduct(hr * constant, min * constant, sec * constant);

	clockProduct.logic();
	return clockProduct;
}

//Adjusts hours, minutes, seconds to standard 24-hour time, carrying over as needed
void ClockType::logic() {
	if (sec >= 60) {
		min += sec / 60;
		sec = sec % 60;
	}
	if (min >= 60) {
		hr += min / 60;
		min = min % 60;
	}
	if (hr >= 24)
		hr = hr % 24;
}

//This is the default constructor, it initialises hr, min, and sec to 0
ClockType::ClockType() {
	hr = 0;
	min = 0;
	sec = 0;
}

//This is a constructor, it takes in 3 integers in the order of hr, min, and sec and
//sets the value when declared
ClockType::ClockType(int hours, int minutes, int seconds) {
	hr = hours;
	min = minutes;
	sec = seconds;
	logic();
}

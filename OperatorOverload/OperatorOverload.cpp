/*This program is user defined to test the functionality of the operator overload. Output is to console.*/
#include <iostream>
#include "ClockType.h"

using namespace std;

int main() {
	ClockType myClock(16, 20, 36);
	ClockType yourClock(23, 49, 56);
	ClockType hisClock;
	ClockType herClock;
	ClockType ourClock;

	ClockType diffClock;
	ClockType sumClock;
	ClockType productClock;

	cout << "---------Comparing myClock to yourClock for equality---------\n";
	if (myClock == yourClock)
		cout << "Yes, myClock and yourClock are the same.\n";
	else
		cout << "No, myClock and yourClock are not the same.\n";
	
	cout << "\n---------herClock = myClock + yourClock and print---------\n";
	herClock = myClock + yourClock;
	herClock.printTime();

	cout << "\n\n---------hisClock = yourClock - myClock and print---------\n";
	hisClock = yourClock - myClock;
	hisClock.printTime();

	cout << "\n\n---------ourClock = herClock * 3 and print---------\n";
	ourClock = herClock * 3;
	ourClock.printTime();

	cout << "\n\n---------Comparing herClock to ourClock using >= ---------\n";
	if (herClock >= ourClock)
		cout << "Yes, herClock is greater than or equal to ourClock\n";
	else
		cout << "No, herClock is not greater than or equal to ourClock\n";

	cout << "\n\n---------Comparing hisClock to ourClock using <= ---------\n";
	if (hisClock <= ourClock)
		cout << "Yes, hisClock is less than or equal to ourClock\n";
	else
		cout << "No, hisClock is not less than or equal to ourClock\n";
}
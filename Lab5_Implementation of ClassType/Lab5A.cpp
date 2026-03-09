/* This program consists a class called ClockType that provides functionality to deal with time.
You are able to: set the time, get the time, print the time, compare the time with another time.*/

#include <iostream>
#include <fstream>
using namespace std;

class clockType
{
public:
	//The setTime function allows you to set the time taking three integers: hours, minutes, and seconds
	//in that order (hr, min, sec)
	void setTime(int, int, int);

	//The getTime function allows you to transfer the values of each of hour, minute and seconds in that 
	//order (hr, min, sec) to the three integer variables you pass.
	void getTime(int&, int&, int&) const;

	//The printTime function prints the time in the format hh:mm:ss
	//It adds zeros for one digit numbers
	void printTime() const;

	//The incrementHours function allows you to increment an hr, it is called by the incrementMinutes function
	// where necessary
	void incrementHours();

	//The incrementMinutes function allows you to increment a min, it is called by the incrementSeconds function
	// where necessary, and also calls the incrementHours function when necessary i.e when minutes are 
	// incremented from 59 to 60, we know that one hour has been completed and the minutes 
	// restart at 0, so the incrementHours is called.
	void incrementMinutes();

	//The incrementSeconds function allows you to increment a sec, it also calls the incrementMinutes function 
	// when necessary i.e when seconds are incremented from 59 to 60, we know that one minute has been
	//completed and the seconds restart at 0, so the incrementMinutes is called.
	void incrementSeconds();

	//The isEqualto function checks whether the time is same as the one which is passed as an argument
	// comparing all of hrs, minutes, and seconds
	bool isEqualto(const clockType&) const;

private:
	int hr, min, sec;
};

int main()
{	
	//LET'S PLAY :)
	//Read in times from file for three clocks and setTime.
	//First clock: printTime, getTime into variables, and then print to test.
	//Second: printTime, incrementSec, printing after each to check, compare with firstClock
	//Third clock: printTime, compare time with first clock.

	ifstream dataIn;
	dataIn.open("times.txt");

	if (!dataIn) {
		cout << "There was an error in opening the file.\n";
		return 1;
	}

	clockType myClock, yourClock, hisClock;
	//variables to be read from file
	int estHr, estMin, estSec; //est for eastern standard time, just a random name.

	//variables to read the data for getTime
	int getHr, getMin, getSec;

	dataIn >> estHr >> estMin >> estSec;
	
	cout << "Testing setTime. No output expected.\n\n";
	myClock.setTime(estHr, estMin, estSec);

	cout << "myClock has 5 6 40, yourClock has 4 59 57, and hisClock has 5 6 40\n\n";

	cout << "Testing printTime function. Printing the contents of myClock: \n";
	myClock.printTime();
	cout << "\n\n";

	myClock.getTime(getHr, getMin, getSec);
	cout << "Printing each of hr, min and sec from getTime in myClock to see that it works fine: \n";
	cout << getHr << "  " << getMin << "  " << getSec << "\n\n";

	dataIn >> estHr >> estMin >> estSec;
	yourClock.setTime(estHr, estMin, estSec);
	cout << "Printing the time in yourClock: \n";
	yourClock.printTime();
	cout << "\n\n";

	cout << "Testing Increment Sec, Min and Hr by calling incrementSec on yourClock: \n";
	for (int i = 0; i < 4; i++) {
		yourClock.incrementSeconds();
		yourClock.printTime();
		cout << "  ";
	}

	cout << "\n\nComparing the time in myClock to yourClock: \n";
	if (myClock.isEqualto(yourClock))
		cout << "Yhup! They're equal.\n";
	else
		cout << "Nope! They're not equal.\n";


	dataIn >> estHr >> estMin >> estSec;
	hisClock.setTime(estHr, estMin, estSec);
	cout << "\nPrinting the time in his clock: \n";
	hisClock.printTime();
	cout << "\n\n";

	cout << "Comparing the time in myClock to hisClock: \n";
	if (myClock.isEqualto(hisClock))
		cout << "Yhup! They're equal.\n";
	else
		cout << "Nope! They're not equal.\n";


} // end main


//The setTime function allows you to set the time taking three integers, hour, minutes, and seconds
//in that order (hr, min, sec)
void clockType::setTime(int hrVal, int minVal, int secVal)
{
	if (hrVal >= 0 && hrVal < 24)
		hr = hrVal;
	else
		hr = 0;
	if (minVal >= 0 && minVal < 60)
		min = minVal;
	else
		min = 0;
	if (secVal >= 0 && secVal < 60)
		sec = secVal;
	else
		sec = 0;
}


//The getTime function allows you to transfer the values of each of hour, minute and seconds in that 
	//order (hr, min, sec) to the three integer variables you pass.
void clockType::getTime(int& hrVal, int& minVal, int& secVal) const
{
	hrVal = hr;
	minVal = min;
	secVal = sec;

}


//The printTime function prints the time in the format hh:mm:ss
//It adds zeros for one digit numbers
void clockType::printTime() const {
	if (hr < 10)
		cout << 0;
	cout << hr << ":";

	if (min < 10)
		cout << 0;
	cout << min << ":";

	if (sec < 10)
		cout << 0;
	cout << sec << " ";
}


//The incrementHours function allows you to increment an hr, it is called by the incrementMinutes function
// where necessary
void clockType::incrementHours() {
	hr++;
	if (hr >= 24)
		hr = 0;
}


//The incrementMinutes function allows you to increment a min, it is called by the incrementSeconds function
// where necessary, and also calls the incrementHours function when necessary i.e when minutes are 
// incremented from 59 to 60, we know that one hour has been completed and the minutes restart at 0, 
// so the incrementHours is called.
void clockType::incrementMinutes() {
	min++;
	if (min >= 60) {
		min = 0;
		incrementHours();
	}

}


//The incrementSeconds function allows you to increment a sec, it also calls the incrementMinutes function when necessary
//i.e when seconds are incremented from 59 to 60, we know that one minute has been completed and the 
// seconds restart at 0, so the incrementMinutes is called.
void clockType::incrementSeconds() {
	sec++;
	if (sec >= 60) {
		sec = 0;
		incrementMinutes();
	}
}


//The isEqualto function checks whether the time is same as the one which is passed as an argument
	// comparing all of hrs, minutes, and seconds
bool clockType::isEqualto(const clockType& otherClock) const {
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}
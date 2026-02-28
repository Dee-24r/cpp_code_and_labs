#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream group1In, group2In;
	ofstream dataOut;
	string courseName1;
	string courseName2;
	double quiz1, quiz2, quiz3, 

	dataOut.open("scorecombo.txt");

	group1In.open("Group1.txt");
	if (!group1In)
		dataOut << "File not opened!";

	group2In.open("Group2.txt");
	if (!group1In)
		dataOut << "File not opened!";

	//while (group1In >> )
}

//#include <fstream>
//#include <iostream>
//#include <string>
//#include <iomanip>
//
//using namespace std;
//
//double avgWithoutLowest(double, double, double, double);
//
//int main() {
//	ifstream dataIn;
//	ofstream dataOut;
//	string lastName, firstName;
//	double quiz1, quiz2, quiz3, quiz4;
//	double average;
//
//	dataIn.open("gradesIn.txt");
//	if (!dataIn)
//		cout << "Error opening file." << endl;
//
//	dataOut.open("gradesOut.txt");
//
//	//HEADERS
//	dataOut << left << setw(13) << "Last Name" << setw(13) << "First Name" << setw(8) << "Quiz 1"
//		<< setw(8) << "Quiz 2" << setw(8) << "Quiz 3" << setw(8) << "Quiz 4" << setw(8) << "Average"
//		<< endl << endl;
//
//	cout << left << setw(13) << "Last Name" << setw(13) << "First Name" << setw(9) << "Quiz 1"
//		<< setw(9) << "Quiz 2" << setw(9) << "Quiz 3" << setw(9) << "Quiz 4" << setw(9) << "Average"
//		<< endl << endl;
//
//	dataOut << fixed << setprecision(2);
//	cout << fixed << setprecision(2);
//
//	while (dataIn >> lastName >> firstName >> quiz1 >> quiz2 >> quiz3 >> quiz4) {
//		average = avgWithoutLowest(quiz1, quiz2, quiz3, quiz4);
//
//		dataOut << left << setw(13) << lastName << setw(13) << firstName << setw(9) << quiz1
//			<< setw(9) << quiz2 << setw(9) << quiz3 << setw(9) << quiz4 << setw(9) << average
//			<< endl;
//
//		cout << left << setw(13) << lastName << setw(13) << firstName << setw(9) << quiz1
//			<< setw(9) << quiz2 << setw(9) << quiz3 << setw(9) << quiz4 << setw(9) << average << endl;
//	}
//
//	dataIn.close();
//	dataOut.close();
//}

////Function to find minimum score
//double avgWithoutLowest(double quiz1, double quiz2, double quiz3, double quiz4) {
//	//Sum up all quiz scores
//	double sumof4 = quiz1 + quiz2 + quiz3 + quiz4;
//	double lowest = quiz1;
//	if (quiz2 < lowest)
//		lowest = quiz2;
//	if (quiz3 < lowest)
//		lowest = quiz3;
//	if (quiz4 < lowest)
//		lowest = quiz4;
//	//Subtract the minimum from the sum of all 4
//	double averageTopThree = (sumof4 - lowest) / 3;
//	return averageTopThree;
//}


/*#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

double averageTopThree(double quiz1, double quiz2,
	double quiz3, double quiz4) {
	//Find mininum
	double min = quiz1;
	if (quiz2 < min)
		min = quiz2;
	if (quiz3 < min)
		min = quiz3;
	if (quiz4 < min)
		min = quiz4;
	//Sum all, then subtract the minimum
	double sum = quiz1 + quiz2 + quiz3 + quiz4;
	double topThreeSum = sum - min;
	return topThreeSum / 3.0;
}

int main()
{
	double quiz1, quiz2, quiz3, quiz4;
	string studentName;
	ifstream dataIn;
	ofstream dataOut;

	dataIn.open("gradesIn.txt");
	dataOut.open("gradesOut.txt");

	if (!dataIn)
		cout << "Error opening file." << endl;
	cout << fixed << setprecision(2);

	//Headers
	cout << left << setw(10) << "NAME" << setw(8) << "QUIZ1"
		<< setw(8) << "QUIZ2" << setw(8) << "QUIZ3" << setw(8)
		<< "QUIZ4" << "AVERAGE" << endl;

	dataOut << left << setw(10) << "NAME" << setw(8) << "QUIZ1"
		<< setw(8) << "QUIZ2" << setw(8) << "QUIZ3" << setw(8)
		<< "QUIZ4" << "AVERAGE" << endl;

	cout << "--------------------------------------------------"
		<< endl;
	dataOut << "--------------------------------------------------"
		<< endl;
	//Processing

	while (dataIn >> studentName >> quiz1 >> quiz2 >> quiz3 >> quiz4)
	{
		double avg = averageTopThree(quiz1, quiz2, quiz3, quiz4);

		cout << left << setw(10) << studentName << setw(8) << quiz1 << setw(8)
			<< quiz2 << setw(8) << quiz3 << setw(8) << quiz4 << setw(8)
			<< avg << endl;

		dataOut << left << setw(10) << studentName << setw(8) << quiz1 << setw(8)
			<< quiz2 << setw(8) << quiz3 << setw(8) << quiz4 << setw(8)
			<< avg << endl;
	}
	dataIn.close();
	dataOut.close();
}
*/

/*#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double avgWithoutLowest(double, double, double, double);
char gradeFunct(double);

int main() {
	ifstream dataIn;
	ofstream dataOut;
	string lastName, firstName;
	double quiz1, quiz2, quiz3, quiz4;
	double average;
	char grade;

	dataIn.open("gradesIn.txt");
	dataOut.open("gradesOut.txt");

	dataOut << left << setw(15) << "Last Name" << setw(15) << "First Name" << setw(9) << "Quiz 1"
		<< setw(9) << "Quiz 2" << setw(9) << "Quiz 3" << setw(9) << "Quiz 4" << setw(9) << "Average"
		<< setw(5) << "Grade" << endl << endl;

	cout << left << setw(15) << "Last Name" << setw(15) << "First Name" << setw(9) << "Quiz 1"
		<< setw(9) << "Quiz 2" << setw(9) << "Quiz 3" << setw(9) << "Quiz 4" << setw(9) << "Average"
		<< setw(5) << "Grade" << endl << endl;

	dataOut << fixed << setprecision(2);
	cout << fixed << setprecision(2);

	while (dataIn >> lastName >> firstName >> quiz1 >> quiz2 >> quiz3 >> quiz4) {
		average = avgWithoutLowest(quiz1, quiz2, quiz3, quiz4);
		grade = gradeFunct(average);

		dataOut << left << setw(15) << lastName << setw(15) << firstName << setw(9) << quiz1
			<< setw(9) << quiz2 << setw(9) << quiz3 << setw(9) << quiz4 << setw(9) << average
			<< setw(5) << grade << endl;

		cout << left << setw(15) << lastName << setw(15) << firstName << setw(9) << quiz1
			<< setw(9) << quiz2 << setw(9) << quiz3 << setw(9) << quiz4 << setw(9) << average
			<< setw(5) << grade << endl;
	}

	dataIn.close();
	dataOut.close();
}

double avgWithoutLowest(double quiz1, double quiz2, double quiz3, double quiz4) {
	double lowest = quiz1;
	if (quiz2 < lowest)
		lowest = quiz2;
	if (quiz3 < lowest)
		lowest = quiz3;
	if (quiz4 < lowest)
		lowest = quiz4;

	return (quiz1 + quiz2 + quiz3 + quiz4 - lowest) / 3;
}

char gradeFunct(double average) {
	if (average >= 90 && average <= 100)
		return 'A';
	else if (average > 80)
		return 'B';
	if (average > 70)
		return 'C';
	if (average > 60)
		return 'D';
	else
		return 'F';
}*/

/*#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool is_dog(char);

int main() {
	ifstream dataIn;
	int noOfDogs = 0;
	string name;
	char animChar;
	double weight, totalWeight = 0, avgDogWeight, noOfBags;

	dataIn.open("RescuePets.txt");
	if (!dataIn) {
		cout << "File not opened!";
		return 1;
	}

	cout << left << setw(25) << "NAME" << setw(10) << "TYPE" << setw(15) << "WEIGHT" << endl;
	cout << setw(41) << setfill('-') << '-' << endl;
	cout << setfill(' ');

	while (dataIn >> name >> animChar >> weight) {
		if (is_dog(animChar) == true) {
			noOfDogs++;
			totalWeight += weight;
		}

		cout << setw(25) << name << setw(10) << animChar << setw(15) << weight << endl;
	}

	avgDogWeight = totalWeight / noOfDogs;
	noOfBags = avgDogWeight / 10;

	cout << endl;
	cout << "There are " << noOfDogs << " dogs in the shelter." << endl;
	cout << "The amount of dog food needed is: " << noOfBags << endl;

	dataIn.close();
}

bool is_dog(char animChar) {
	if (animChar == 'd')
		return true;
	return false;
}*/
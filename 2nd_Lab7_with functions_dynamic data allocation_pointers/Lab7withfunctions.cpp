//COMMENTS
//This program dynamically allocates an array with number of elements based on user’s input, and stores
// the readin scores in the array.
// The input is from a file called studentRecords.txt
//It then calculates and prints the average of the scores, along with all the scores, first in usual order, and
// then in reverse order.
//addy for address
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

char calcGrade(double avg);

int main() {
	ifstream dataIn("studentRecords.txt");

	if (!dataIn) {
		cout << "There was an error opening the file";
		return 1;
	}

	class studentType {
	public:
		studentType();
		studentType(const studentType& astudentObj);
		~studentType();
		void printContent()const;
		void inputContent();
	private:
		char name[26];
		float avg;
		int sID;
		char grade;
	};

	/*struct studentType {
		char name[26];
		float avg;
		int sID;
		char grade;
		//~studentType();
	};*/

	int i;
	int noOfStudents;

	studentType* studentAddy;
	studentType* backUpAddy;

	cout << "Hey, Prof. Hills. Please, enter the number of students: ";
	cin >> noOfStudents;
	studentAddy = new studentType[noOfStudents];
	backUpAddy = studentAddy;

	for (i = 0; i < noOfStudents; i++) {
		dataIn >> (*studentAddy).name;
		dataIn >> (*studentAddy).avg;
		dataIn >> studentAddy->sID;
		studentAddy->grade = calcGrade(studentAddy->avg);
		studentAddy++;
	}

	cout << "This is being displayed in the usual order: \n";

	cout << left;
	studentAddy = backUpAddy;
	for (i = 0; i < noOfStudents; i++) {
		cout << setw(10) << (*studentAddy).name << setw(7) << (*studentAddy).avg << setw(7) << (*studentAddy).sID << setw(3)
			<< (*studentAddy).grade << "\n";
		studentAddy++;
	}

	cout << "\n\n";
	cout << "This is being displayed in reverse order (starting from the last student to the first): \n";

	studentAddy = backUpAddy + (noOfStudents - 1);

	for (i = 0; i < noOfStudents; i++) {
		cout << setw(10) << (*studentAddy).name << setw(7) << (*studentAddy).avg << setw(7) << (*studentAddy).sID << setw(3)
			<< (*studentAddy).grade << "\n";
		studentAddy--;
	}

	delete[] backUpAddy;
	dataIn.close();

	return 0;
}

char calcGrade(double avg) {
	char grade;
	if (avg >= 90)
		grade = 'A';
	else if (avg >= 80)
		grade = 'B';
	else if (avg >= 70)
		grade = 'C';
	else if (avg >= 60)
		grade = 'D';
	else if (avg >= 50)
		grade = 'E';
	else
		grade = 'F';

	return grade;
}

//~studentType();

//studentType::studentType() {
	//delete p[];
//}
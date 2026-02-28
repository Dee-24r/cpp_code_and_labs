/*This program dynamically allocates two integer arrays. It prints the content of both and then, uses
a function which takes in the two pointer variables to swap thir values. It prints the values 
of both after the swap. Input is from the user, and output is to the console.*/
#include <iostream>
using namespace std;

void swapArrays(int*, int*, int);
void printMembers(int*, int);

int main() {
	int i, size;
	int * amysScores, * jennysScores;
	cout << "Enter the size of the arrays (one size for both): ";
	cin >> size;

	amysScores = new int[size];
	jennysScores = new int[size];

	cout << "Enter " << size << " scores for Amy: ";
	for (i = 0; i < size; i++)
		cin >> amysScores[i];

	cout << "\nEnter " << size << " scores for Jenny: ";
	for (i = 0; i < size; i++)
		cin >> jennysScores[i];

	cout << "\n--------Before the swap--------\n";
	cout << "\nThese are Amy's Scores\n";
	printMembers(amysScores, size);

	cout << "\nThese are Jenny's Scores\n";
	printMembers(jennysScores, size);

	swapArrays(amysScores, jennysScores, size);

	cout << "\n\n--------After the swap--------\n";
	cout << "\nThese are Amy's Scores\n";
	printMembers(amysScores, size);

	cout << "\nThese are Jenny's Scores\n";
	printMembers(jennysScores, size);
	cout << "\n\n";

	delete [] amysScores;
	delete[] jennysScores;

	return 0;
}

/*This function takes two integer pointers - ideally equally sized and hold dynamically allocated arrays
and the size of the arrays. It swaps the values of the arrays.*/
void swapArrays(int *p, int *q, int size) {
	int i;
	int *temp;
	temp = new int[size];
	for (i = 0; i < size; i++)
		temp[i] = p[i];
	for (i = 0; i < size; i++)
		p[i] = q[i];
	for (i = 0; i < size; i++)
		q[i] = temp[i];

	delete[] temp;
}

/*This function takes in a dynamically allocated int array, along with its size and prints
the contents of the array*/
void printMembers(int *myArray, int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << myArray[i] << "  ";
}
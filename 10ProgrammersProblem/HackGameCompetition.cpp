/*This program uses the header file hackerRank.h. (Not the real Hacker Rank, I just called it that.)
It runs the code for two games/file inputs. For each, it reads in lines of codes and comments 
and determines the winner (the first whose lines of code reaches a 1000). It calls functions to:
1) echoPrint the input and determine the winner.
2) to display the programmers' data, and
3) to determine how many programmers it took to beat the winner.

The input is read in from file and the output is printed to console.*/
#include <iostream>
#include <fstream>
#include <iomanip>

#include "hackerRank.h"
using namespace std;

//Prototypes
//Takes in the array of hackerRank type, reads in the submissions, echos it, flags the winner and returns 
// their ID (not index)
int echoPrintInput(ifstream &, hackerRank []);
//Takes in the array of hackerRank type, and prints out all the total scores that were read in for each user
void printProgrammers(hackerRank []);
//This takes in the ID of the winner, and the array of hackerRank datatype and determines and prints
// the smallest k such that programmers 1 through k (excluding the winner, if he/she is in the first k) 
// have turned in more lines than the winner in a descriptive message.
void detNoToBeatWinner(int, const hackerRank []);

int main() {
	ifstream dataIn;
	hackerRank programmers[10];
	int winner;

	//First Competition - Program11
	dataIn.open("program11.txt");

	if (!dataIn) {
		cout << "There was an error opening the file";
		return 1;
	}

	cout << "Game 1\n\n";
	winner = echoPrintInput(dataIn, programmers);//actual programmer ID, not index in array.
	printProgrammers(programmers);
	detNoToBeatWinner(winner, programmers);

	dataIn.close();
	cout << "\n\n\n";

	//Second Competition - Program12
	dataIn.open("program12.txt");

	if (!dataIn) {
		cout << "There was an error opening the file";
		return 1;
	}

	cout << "Game 2\n\n";
	winner = echoPrintInput(dataIn, programmers);//actual programmer ID, not index in array.
	printProgrammers(programmers);
	detNoToBeatWinner(winner, programmers);

	dataIn.close();
}

//Takes in the array of hackerRank type, reads in the submissions, echos it, flags the winner and returns 
// their ID (not index)
int echoPrintInput(ifstream &dataIn, hackerRank arrVar[]) {
	int pID = 0, codeLines = 0, comments = 0;
	cout << left << "PROGRAMMERS' PROGRESS" << endl;
	cout << setw(13) << "Programmer" << setw(16) << "Lines of Code" << setw(20) << "Lines of Comments" << endl;

	//initialise data members for each programmer
	for (int i = 0; i < 10; i++) {
		arrVar[i].linesOfCode = 0;
		arrVar[i].commentLines = 0;
	}

	//read in, add up scores
	while (dataIn >> pID >> codeLines >> comments){
		cout << endl;
		arrVar[pID - 1].linesOfCode += codeLines;
		arrVar[pID - 1].commentLines += comments;
		cout << setw(13) << pID << setw(16) << codeLines << setw(20) << comments;
		//flag winner and return ID
		if (arrVar[pID - 1].linesOfCode >= 1000) {
			cout << "-----WINNER-----" << endl;
			cout << "WINNER: Programmer " << pID << endl << endl;
			return pID;
		}
	}

	//In the case that all the input is read and there is no winner from the data.
	cout << "Every input read in. No winner, yet!" << endl;
	return -1;
}

//Takes in the array of hackerRank type, and prints out all the total scores that were read in for each user
void printProgrammers(hackerRank arrVar[]) {
	cout << "FINAL TOTALS" << endl;
	cout << setw(13) << "Programmer" << setw(16) << "Lines of Code" << setw(20) << "Lines of Comments" << endl << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(13) << i + 1 << setw(16) << arrVar[i].linesOfCode << setw(20)
			<< arrVar[i].commentLines << endl;
	}
}

//This takes in the ID of the winner, and the array of hackerRank datatype and determines and prints
// the smallest k such that programmers 1 through k (excluding the winner, if he/she is in the first k) 
// have turned in more lines than the winner in a descriptive message.
void detNoToBeatWinner(int winnerID, const hackerRank arrVar[]) {
	int i, sumToBeatWinner = 0;
	for (i = 0; i < 10; i++) {
		if (i != winnerID - 1)
			sumToBeatWinner += arrVar[i].linesOfCode;

		if (sumToBeatWinner > arrVar[winnerID - 1].linesOfCode)
			break;
	}
	cout << "It took programmers 1 through " << i+1 << " to produce more than the winner's results.\n";
}
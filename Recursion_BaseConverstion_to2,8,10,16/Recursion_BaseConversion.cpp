// This program converts the number input in base 10 to another base including 2, 8, 10, and 16.
// Input: Prompt a user from the console to enter a number.
// Output: The original number and its converted value.
#include <iostream>
using namespace std;

//This function takes in a number in base 10 and a desired base and converts it to the base 
void Convert(int num, int base);

int main()
{
	int num = 0;
	int base = 0;

	do
	{
		cout << "\nEnter a base 10 number here or enter '999' to terminate: ";
		cin >> num;

		if (num == 999)
			break;

		cout << "Enter the base that you want this converted to: ";
		cin >> base;

		cout << "\nConversion: " << num << " = ";
		Convert(num, base);
		cout << " in base " << base;
		cout << "\nThis is it!" << endl;
	} while (num != 999);

	return 0;
} //end main

//This function takes in a number in base 10 and a desired base and converts it to the base
void Convert(int num, int base)
{
	if (num != 0)
	{
		Convert(num / base, base);
		int remainder = num % base;

		if (base == 16 && remainder >= 10) {
			char let;
			switch (remainder) {
			case 10:
				let = 'A';
				break;
			case 11:
				let = 'B';
				break;
			case 12:
				let = 'C';
				break;
			case 13:
				let = 'D';
				break;
			case 14:
				let = 'E';
				break;
			case 15:
				let = 'F';
				break;
			}
			cout << let;
		}
		
		else
			cout << remainder;
	} //end if

} //end Convert
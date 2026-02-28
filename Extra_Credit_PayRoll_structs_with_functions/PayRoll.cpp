/*This program reads records of employees first and last names, pay per hour and number of hours worked
from a file. It calculates their overtime hours and overtime pay as 1.5 of their regular pay.
It calculates their complete pay and net salary.
It prints out their names, pay per hour, number of hours worked, overtime hours, pay, taxes paid 
and netsalary.
INPUT: FROM A FILE named employeePay.txt
Output: To console in formatted style
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

ifstream dataIn("employeePay.txt");
struct employeePay{
	string firstName;  //read
	string lastName;  //read
	double payPerHour; //read
	int hrsWorked;  //read
	int overtimeHrs;
	double pay;
	double taxesPaid;
	double netSalary;
};

int regularHrs = 40; //For the company to decide

void readInput(employeePay&);
void calcAndUpdate(employeePay&);
void printPayRoll(const employeePay&);

int main() {
	int i, numberOfEmp = 300;
	if (!dataIn) {
		cout << "There was an error opening this file";
		return 1;
	}

	employeePay processEmployee;
	cout << left << fixed << setprecision(2);
	cout << setw(13) << "Last Name" << setw(13) << "First Name" << setw(13) << "Pay per hr"
		<< setw(9) << "Hours" << setw(11) << "Overtime" << setw(11) << "Pay"
		<< setw(11) << "Taxes" << setw(11) << "Net Salary" << "\n\n";

	//readInput(processEmployee);
	//for (i = 0; i < numberOfEmp && (!dataIn.eof()); i++){
	//while (!dataIn.eof()) {
	while (!dataIn.eof()){
		readInput(processEmployee);
		calcAndUpdate(processEmployee);
		printPayRoll(processEmployee);
		//readInput(processEmployee);
	}

	dataIn.close();
	return 0;
}

void readInput(employeePay& procEmp) {
	dataIn >> procEmp.firstName >> procEmp.lastName >> procEmp.payPerHour >> procEmp.hrsWorked;
}

void calcAndUpdate(employeePay& procEmp) {
	if (procEmp.hrsWorked > regularHrs) {
		procEmp.overtimeHrs = procEmp.hrsWorked - regularHrs;
		procEmp.pay = ((procEmp.overtimeHrs * 1.5) + regularHrs) * procEmp.payPerHour; //overtime hrs *1.5
	}                                             // added to regular Hours and multiply by 30.
	else {
		procEmp.overtimeHrs = 0;
		procEmp.pay = procEmp.hrsWorked * procEmp.payPerHour;
	}

	procEmp.netSalary = 0.92 * procEmp.pay; //0.92 = 92% = 100-8%
	procEmp.taxesPaid = 0.08 * procEmp.pay; //8%
}

void printPayRoll(const employeePay& procEmp) { //I guess this could be 
	cout << setw(13) << procEmp.lastName << setw(13) << procEmp.firstName << setw(13) << procEmp.payPerHour
		<< setw(9) << procEmp.hrsWorked << setw(11) << procEmp.overtimeHrs
		<< setw(11) << procEmp.pay << setw(11) << procEmp.taxesPaid << setw(11) << procEmp.netSalary << "\n";
}
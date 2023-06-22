/*Marissa Sihapanya
May 31, 2023*/
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>
using namespace std;
#include "Bank.h"

int main() {
	double openingAmount;
	double depositAmount;
	double interestRate;
	int userYears;
	// get the user's initial inputs
	cout << "*********************************" << endl;
	cout << "********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cin >> openingAmount;
	cout << "Monthly deposit: " << endl;
	cin >> depositAmount;
	cout << "Annual interest: " << endl;
	cin >> interestRate;
	cout << "Number of years: " << endl;
	cin >> userYears;
	// create a vector to store each balance per year
	vector<double> balances(userYears);
	cout << "Press any key to continue >> . . ." << endl;
	// create our bank report objects
	Bank bankReport1(openingAmount, depositAmount, interestRate, userYears);
	Bank bankReport2(openingAmount, depositAmount, interestRate, userYears);
	// allow user to press any key to continue
	_getch();
	// assign the user's values to the bank report's values
	bankReport1.SetEarnedInterest(openingAmount, depositAmount, interestRate, false);
	bankReport1.SetClosingBalance(openingAmount, depositAmount, bankReport1.GetEarnedInterest(), false);
	bankReport1.SetEarnedInterest(openingAmount, depositAmount, interestRate, false);
	bankReport2.SetEarnedInterest(openingAmount, depositAmount, interestRate, true);
	bankReport2.SetClosingBalance(openingAmount, depositAmount, bankReport1.GetEarnedInterest(), true);
	bankReport2.SetEarnedInterest(openingAmount, depositAmount, interestRate, true);
	// display the two reports
	cout << "================================================================" << endl;
	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << left << setw(15) << "Year" << setw(25) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < bankReport1.GetYear(userYears); ++i) {
		double balance = bankReport1.GetClosingBalance();
		double earnedInterest = bankReport1.GetEarnedInterest();
		bankReport1.DisplayReports(bankReport1.GetYear(i+1), balance, earnedInterest);
		bankReport1.SetEarnedInterest(balance, depositAmount, interestRate, false);
		bankReport1.SetClosingBalance(balance, depositAmount, earnedInterest, false);
		balance += earnedInterest;
	}
	cout << "================================================================" << endl;
	cout << "    Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << left << setw(15) << "Year" << setw(25) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	for (int i = 0; i < bankReport2.GetYear(userYears); ++i) {
		double balance = bankReport2.GetClosingBalance();
		double earnedInterest = bankReport2.GetEarnedInterest();
		bankReport2.DisplayReports(bankReport2.GetYear(i+1), balance, earnedInterest);
		bankReport2.SetEarnedInterest(balance, depositAmount, interestRate, true);
		bankReport2.SetClosingBalance(balance, depositAmount, earnedInterest, true);
		balance += earnedInterest;
	}
}

#include <iostream>
#include <iomanip>

using namespace std;

#include "Bank.h"

Bank::Bank() {
	initialAmount = 0.0;
	depositAmount = 0.0;
	interestRate = 0.0;
	userYears = 0;
	closingBalance = 0.0;
	earnedInterest = 0.0;
}

Bank::Bank(double amount, double deposit, double interest, int years) {
	initialAmount = amount;
	depositAmount = deposit;
	interestRate = interest;
	userYears = years;
}

void Bank::SetInitialAmount(double amount) {
	initialAmount = amount;
}

double Bank::GetInitialAmount() {
	return initialAmount;
}

void Bank::SetClosingBalance(double amount, double deposit, double earned, bool depositTrue) {
	if (depositTrue) {
		closingBalance = (amount + (deposit * 12) + earned);
	}
	else {
		closingBalance = amount + earned;
	}
	
}

double Bank::GetClosingBalance() {
	return closingBalance;
}

void Bank::SetMonthlyDeposit(double deposit) {
	depositAmount = deposit;
}

double Bank::GetMonthlyDeposit() {
	return depositAmount;
}

void Bank::SetEarnedInterest(double balance, double deposit, double interest, bool depositTrue) {
	if (depositTrue) {
		earnedInterest = (balance + deposit * 12) * (interest / 100.0);
	}
	else {
		earnedInterest = balance * (interest / 100.0);
	}
	
}

double Bank::GetEarnedInterest() {
	return earnedInterest;
}

void Bank::SetYear(int year) {
	userYears = year;
}

int Bank::GetYear(int currentYear) {
	return currentYear;
}

void Bank::DisplayReports(int year, double balance, double earned) {
	cout << left << setw(15) << year << setw(25) << fixed << setprecision(2) << balance << setw(25) << fixed << setprecision(2) << earned << endl;

}
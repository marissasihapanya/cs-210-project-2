#ifndef BANK_H
#define BANK_H

using namespace std;

class Bank {
	public:
		void DisplayReports(int year, double balance, double earned);
		void SetInitialAmount(double initialAmount);
		void SetClosingBalance(double closingBalance, double depositAmount, double earned, bool depositTrue);
		void SetMonthlyDeposit(double depositAmount);
		void SetEarnedInterest(double initialAmount, double depositAmount, double interestRate, bool depositTrue);
		void SetYear(int year);
		double GetInitialAmount();
		double GetClosingBalance();
		double GetMonthlyDeposit();
		double GetEarnedInterest();
		int GetYear(int currentYear);
		Bank();
		Bank(double initialAmount, double depositAmount, double interestRate, int userYears);

	private:
		double initialAmount;
		double depositAmount;
		double interestRate;
		double earnedInterest;
		int userYears;
		double closingBalance;

};




#endif
/*
    This program calculates the monthly payment for a mortgage based on
    user input.

    The program:
    - Repeatedly asks the user to enter their account number.
      Entering -1 will terminate the program.
    - For each account, asks the user to enter:
        * Mortgage amount (in dollars)
        * Mortgage term (in years)
        * Interest rate (as a decimal, e.g., 0.05 for 5%)
    - Computes the total payment using simple interest:
          Total Payment = Principal + (Principal * Term * Interest Rate)
    - Calculates the monthly payment by dividing the total payment by
      the total number of months (Term * 12)
    - Displays the monthly payable amount.
*/

#include <iostream>
using namespace std;

int main()
{
    int accountNumber;
    int morgageAmmount;
    int morgageTerm;
    double interestRate;

    int total = 0;
    int months;

    cout << "Enter Your Account Number (-1 to quit)" << endl;
    cin >> accountNumber;
    while (accountNumber != -1)
    {
        cout << "Enter mortgage amount (in dollars): " << endl;
        cin >> morgageAmmount;
        cout << "Enter mortgage term (in years): " << endl;
        cin >> morgageTerm;
        cout << "Enter interest rate (as a decimal): " << endl;
        cin >> interestRate;
        total = (morgageAmmount * morgageTerm * interestRate) + morgageAmmount;
        months = total / (morgageTerm * 12);
        cout << "The monthly payable interest: " << months << endl;

        cout << "Enter Your Account Number (-1 to quit)" << endl;
        cin >> accountNumber;

        return 0;
    }
}
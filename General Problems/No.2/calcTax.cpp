/*
    This program calculates and displays sales and taxes for each month
    based on the total amount collected.

    The program:
    - Repeatedly asks the user to enter the total amount collected.
      Entering -1 will terminate the program.
    - For each month, asks the user to enter the name of the month.
    - Computes the actual sales by dividing the total collected by 1.09.
    - Calculates and displays:
        * County Sales Tax (5% of sales)
        * State Sales Tax (4% of sales)
    - Displays the total collection and the computed sales and taxes.
*/

#include <iostream>
using namespace std;

int main()
{
    double totalAmountCollected;
    string nameOfMonth;
    double sales = 0;

    cout << "Enter Total Amount Collected (-1 to quit)" << endl;
    cin >> totalAmountCollected;

    while (totalAmountCollected != -1)
    {
        cout << "Enter Name Of Month" << endl;
        cin >> nameOfMonth;

        cout << "Total Collection is: " << totalAmountCollected << "$" << endl;
        sales = totalAmountCollected / 1.09;
        cout << "Sales: " << sales << "$" << endl;
        cout << "County Sales Tax: " << sales * 0.05 << "$" << endl;
        cout << "State Sales Tax: " << sales * 0.04 << "$" << endl;

        cout << "Enter Total Amount Collected (-1 to quit)" << endl;
        cin >> totalAmountCollected;
    }
    return 0;
}
/*
    This program calculates an employee's weekly salary based on their
    sales.

    The program:
    - Repeatedly asks the user to enter the sales amount in dollars.
      Entering -1 will terminate the program.
    - Calculates the salary using the formula:
          Salary = $200 + 9% of sales
    - Displays the calculated salary for each sales input.
*/

#include <iostream>
using namespace std;
int main()
{
    double salesInDollars = 0;
    cout << "Enter sales in dollars (-1 to end): " << endl;
    cin >> salesInDollars;
    while (salesInDollars != -1)
    {
        cout << "Salary is: " << (salesInDollars * 0.09) + 200 << "$" << endl;
        cout << "Enter sales in dollars (-1 to end): " << endl;
        cin >> salesInDollars;
    }
    return 0;
}
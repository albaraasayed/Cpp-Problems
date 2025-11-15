/*
    This program asks the user to enter a number N, then calculates an
    approximation of π using the first N terms of the Leibniz series:

        π = 4 * (1 - 1/3 + 1/5 - 1/7 + ...)

    The program:
    - Starts with a sum equal to 0
    - Uses a loop to generate odd denominators (1, 3, 5, 7, ...)
    - Adds the term when the index is even, subtracts it when odd
    - Multiplies the final sum by 4 and prints the approximation of π
*/

#include <iostream>
using namespace std;

int main()
{
    int userNumber;
    cout << "Enter the Number of N" << endl;
    cin >> userNumber;
    double addingNumber = 0.0;

    for (int i = 0, j = 1; i < userNumber; i++, j += 2)
    {
        if (i % 2 == 0)
        {
            addingNumber += (1.0 / j);
        }
        else
        {
            addingNumber -= (1.0 / j);
        }
    }
    cout << addingNumber * 4.0 << endl;

    return 0;
}
/*
    This function takes an integer and returns the sum of its digits.
    Example: If num = 472, the function returns 4 + 7 + 2 = 13.

    The function:
    - Extracts each digit using modulus (%) and division (/)
    - Accumulates the digits into a sum
    - Returns the final total
*/

#include <iostream>
using namespace std;
int sumOfDigits(int num);
int main()
{
    int number;
    cin >> number;
    cout << sumOfDigits(number) << endl;
    return 0;
}

int sumOfDigits(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

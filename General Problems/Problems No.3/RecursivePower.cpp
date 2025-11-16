/*
    This function computes a^b (a raised to the power b) using recursion.

    The function:
    - Returns 1 when the exponent b is 0 (base case)
    - Otherwise multiplies 'a' by power(a, b - 1)
    - Continues recursively until b reaches 0
*/
#include <iostream>
using namespace std;
int power(int a, int b);
int main()
{
    int base, exponent;
    cin >> base >> exponent;
    cout << power(base, exponent) << endl;
    return 0;
}
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return a * power(a, b - 1);
    }
}
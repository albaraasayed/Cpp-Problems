/*
    This function prints the Fibonacci number at position 'nth'.

    The function:
    - Uses an iterative approach (no recursion)
    - Starts with:
          num1 = 0  (F0)
          num2 = 1  (F1)
    - Handles the base cases:
          nth = 0 → prints 0
          nth = 1 → prints 1
    - For nth ≥ 2:
          Repeatedly updates the two previous Fibonacci numbers
          until reaching the nth term
    - Finally prints:
          The index (nth)
          The Fibonacci number at that position
*/

#include <iostream>
using namespace std;
void fibonacciNumber(int nth);
int main()
{
    int n;
    cin >> n;
    fibonacciNumber(n);
    return 0;
}
void fibonacciNumber(int nth)
{
    unsigned long long num1 = 0;
    unsigned long long num2 = 1;

    if (nth == 0)
    {
        cout << 0 << endl;
        return;
    }

    if (nth == 1)
    {
        cout << 1 << endl;
        return;
    }

    for (int i = 2; i <= nth; i++)
    {
        unsigned long long next = num1 + num2;
        num1 = num2;
        num2 = next;
    }

    cout << num2 << endl;
}
/*
    A company pays its salespeople a weekly salary consisting of:
        - A base pay of $200
        - Plus 9% commission of their weekly gross sales

    Example:
        Gross sales = $3000
        Salary = 200 + (0.09 * 3000) = $470

    Task:
        Write a program that:
        - Reads gross sales amounts for multiple salespeople
        - Calculates each salesperson's weekly salary
        - Places their salary (truncated to an integer) into one of the
          following salary ranges:

            a) $200–299
            b) $300–399
            c) $400–499
            d) $500–599
            e) $600–699
            f) $700–799
            g) $800–899
            h) $900–999
            i) $1000 and over

        - Use an array of 9 counters to store how many salespeople fall
          into each salary range

*/

#include <iostream>
using namespace std;

void salesPeople()
{
    int arr[9] = {0};
    double sales;

    cout << "Enter gross sales (-1 to end): ";
    cin >> sales;

    while (sales != -1)
    {
        double salary = 200 + 0.09 * sales;
        int s = (int)salary;

        if (s >= 200 && s < 300)
            arr[0]++;
        else if (s < 400)
            arr[1]++;
        else if (s < 500)
            arr[2]++;
        else if (s < 600)
            arr[3]++;
        else if (s < 700)
            arr[4]++;
        else if (s < 800)
            arr[5]++;
        else if (s < 900)
            arr[6]++;
        else if (s < 1000)
            arr[7]++;
        else
            arr[8]++;

        cout << "Enter gross sales (-1 to end): ";
        cin >> sales;
    }

    cout << "[";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << ", ";
    cout << arr[8] << "]" << endl;
}

int main()
{
    salesPeople();
    return 0;
}

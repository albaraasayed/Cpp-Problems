/*
    This program calculates parking charges for up to 3 cars based on
    the number of hours each car was parked.

    The program:
    - Reads the number of hours each car was parked (maximum 72 hours).
      Invalid inputs (less than 0 or greater than 72) are rejected.
    - Computes charges based on the following rules:
        * Up to 8 hours: $25 + $0.50 per hour
        * More than 8 hours and less than 24: $25 + $5 per additional hour, capped at $50, plus $0.50 per hour
        * 24 to 48 hours: $50 per day + $5 per extra hour, capped at $100, plus $0.50 per hour
        * 48 to 72 hours: $100 per 2 days + $5 per extra hour, capped at $150, plus $0.50 per hour
    - Displays the charge for each car, as well as the total hours and total charges.
*/
#include <iostream>
using namespace std;
void charges();

int main()
{
    charges();
    return 0;
}

void charges()
{
    int CustomersHours[3];
    float cost = 0.0;
    float costOfDay = 50.0;
    int days = 0;
    int hours = 0;
    int totalCharges = 0;
    int totalHours = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> CustomersHours[i];
        if (CustomersHours[i] > 0 && CustomersHours[i] <= 72)
        {
            if (CustomersHours[i] > 8 && CustomersHours[i] < 24)
            {
                cost = 25;
                hours = CustomersHours[i] - 8.0;
                cost += hours * 5.0;
                if (cost > 50)
                {
                    cost = 50;
                }
                cost += 0.5 * CustomersHours[i];
            }
            else if (CustomersHours[i] >= 24 && CustomersHours[i] < 48)
            {
                days = 1;
                cost = days * costOfDay;
                hours = CustomersHours[i] - (days * 24);
                cost += hours * 5.0;
                if (cost > 100)
                {
                    cost = 100;
                }
                cost += 0.5 * CustomersHours[i];
            }
            else if (CustomersHours[i] >= 48 && CustomersHours[i] < 72)
            {
                days = 2;
                cost = days * costOfDay;
                hours = CustomersHours[i] - (days * 24);
                cost += hours * 5.0;
                if (cost > 150)
                {
                    cost = 150;
                }
                cost += 0.5 * CustomersHours[i];
            }
            else
            {
                cost = 25 + (0.5 * CustomersHours[i]);
            }
            cout << "Car:" << i + 1 << "    Hours: " << CustomersHours[i] << "    Charge: " << cost << endl;
            totalCharges += cost;
            totalHours += CustomersHours[i];
        }
        else
        {
            cout << "You can't put number above 72 and below 0" << endl;
        }
    }
    cout << "Total: " << "  Hours: " << totalHours << "    Charge: " << totalCharges << endl;
}
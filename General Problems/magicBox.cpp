/*
The Question:
Write a C++ program that asks the user to enter the size of a Magic Box (an odd integer greater than 1). The program should then generate the positions of numbers from 1 to n² inside the magic square using the Siamese method:
    - Start by placing the number 1 in row = 1 and column = (size + 1) / 2.
    - For each next number:
        - If the previous number is a multiple of the size, move down one row.
        - Otherwise, move up-left (row–1, col–1).
    - If movement goes out of bounds:
        - Wrap around to the opposite side.
Your program should print for every number n its corresponding row and column in the magic box in the format:
    - n = <number>, r = <row>, col = <column>
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size of Magic Box " << endl;
    int size;
    cin >> size;
    if (size % 2 != 0 && size != 1)
    {
        int tableSize = size * size;
        int row = 1;
        int col = (size + 1) / 2;
        cout << "n= " << 1 << ", r= " << row << ", col= " << col << endl;
        for (int n = 2; n <= size * size; n++)
        {
            if ((n - 1) % size == 0)
            {
                row++;
                if (!(row > size))
                {
                    row = 1;
                }
                cout << "n= " << n << ", r= " << row << ", col= " << col << endl;
            }
            else
            {
                col--;
                row--;
                if (col < 1)
                {
                    col = size;
                }
                if (row < 1)
                {
                    row = size;
                }
                cout << "n= " << n << ", r= " << row << ", col= " << col << endl;
            }
        }
    }

    return 0;
}

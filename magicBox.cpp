/*  */

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

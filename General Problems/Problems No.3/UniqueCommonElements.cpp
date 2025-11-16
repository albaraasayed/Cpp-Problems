/*
    Problem: Unique Common Elements in Two Arrays

    - Read two sets of numbers, each containing 10 numbers.
    - Find the elements that are common to both arrays.
    - Ensure that each common element is displayed **only once** (unique).
    - Display the unique common elements.
*/

#include <iostream>
using namespace std;

void uniqueValuesInArrays()
{
    int arr1[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter number " << (i + 1) << " for first array: ";
        cin >> arr1[i];
    }

    int arr2[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter number " << (i + 1) << " for second array: ";
        cin >> arr2[i];
    }
    int arr3[10] = {0};
    int index = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr1[i] == arr2[j])
            {
                bool isHere = false;
                for (int k = 0; k < index; k++)
                {
                    if (arr1[i] == arr3[k])
                    {
                        isHere = true;
                        break;
                    }
                }

                if (!isHere)
                {
                    arr3[index] = arr1[i];
                    index++;
                }
            }
        }
    }

    cout << "Unique common elements: ";
    for (int i = 0; i < index; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
}

int main()
{
    uniqueValuesInArrays();
    return 0;
}

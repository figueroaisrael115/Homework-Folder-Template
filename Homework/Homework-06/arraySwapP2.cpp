#include <iostream>

void swap(int array[], int size, int array2[], int size2)
{
    std::cout << "Numbers in both arrays: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if ((array[i] == array2[j]))
            {
                std::cout << array[i] << " ";
                break;
            }
        }
    }
}
int main()
{
    int data[]{1, 3, 6, 7, 9};
    int data2[]{5, 3, 3, 11};
    swap(data, 5, data2, 4);
    return 0;
}
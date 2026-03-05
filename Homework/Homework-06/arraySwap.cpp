#include <iostream>

int main()
{
    int data[]{1, 3, 6, 7, 9};
    int data2[]{5, 3, 3, 11};

    for (int i = 0; i < 4; i++)
    {
        data[i] = data[i] + data2[i];

        data2[i] = data[i] - data2[i];

        data[i] = data[i] - data2[i];
    }
    for (int x : data2)
    {

        std::cout << x << " ";
    }
    return 0;
}
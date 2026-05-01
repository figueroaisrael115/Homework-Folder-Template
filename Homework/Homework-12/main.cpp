#include <iostream>
#include <vector>

int main()
{
    // Initialize the two vector values
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    // insert elements from numbers2 into numbers1. Since i'm adding an element--
    // shifting everything to the right, we increment the insert by 2 each time.
    int insertPos = 1;
    for (int i = 0; i < numbers2.size(); i++)
    {
        // iterator to place the value
        numbers1.insert(numbers1.begin() + insertPos, numbers2[i]);
        insertPos += 2;
    }

    // Print the vector using a range-based for loop
    std::cout << "Vector (numbers1): ";
    for (int num : numbers1)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
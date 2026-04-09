#include <iostream>
#include <stdexcept>
#include <string>

class CustomException : public std::runtime_error {
public:
    CustomException(const std::string& message) : std::runtime_error(message) {}
};
// Division
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(numerator) / denominator;
}

// Array
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
    return arr[index];
}

// Nested Exception
void nestedFunction() {
    throw CustomException("Error in nestedFunction");
}

void outerFunction() {
    try {
        nestedFunction();
    } catch (const CustomException& e) {
        std::cout << "Caught exception in outerFunction: " << e.what() << std::endl;
        throw; 
    }
}

int main() {
    try {
        outerFunction();
    } catch (const CustomException& e) {
        std::cout << "Caught rethrown exception in main: " << e.what() << std::endl;
    }
    int num, den;
    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> den;

    try {
        double result = divide(num, den);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    int size, idx;
    std::cout << "Enter array size: ";
    std::cin >> size;
    
    int* myArray = new int[size];
    for(int i = 0; i < size; i++) {
        myArray[i] = (i + 1) * 10; 
    }

    std::cout << "Enter index to access: ";
    std::cin >> idx;

    try {
        int value = accessArray(myArray, size, idx);
        std::cout << "Value at index " << idx << " is " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    delete[] myArray;

    return 0;
}
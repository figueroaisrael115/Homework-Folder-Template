#include <iostream>
#include <iomanip>
#include <cmath>
int main()
{
    std::cout << "1) Calculate the area of a square" << std::endl;
    std::cout << "2) Calculate the area of a rectangle" << std::endl;
    std::cout << "3) Calculate the area of a circle" << std::endl;
    std::cout << "4) Calculate the area of a cylinder" << std::endl;
    int choice;
    std::cout << "Enter your choice (1-4): " << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        std::cout << "Enter the side length of your square" << std::endl;
        double side;
        std::cin >> side;
        double squareArea = side * side;
        std::cout << "The area of your square is: " << squareArea << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "Enter the length and width of your rectangle: " << std::endl;
        double length, width;
        std::cin >> length >> width;
        double rectangleArea = length * width;
        std::cout << "The area of your rectangle is: " << rectangleArea << std::endl;
        break;
    }
    case 3:
    {
        std::cout << "Enter the radius of your circle: " << std::endl;
        double radius;
        std::cin >> radius;
        double circleArea = M_PI * (radius * radius);
        std::cout << "The area of your circle is: " << circleArea << std::endl;
        break;
    }
    case 4:
    {
        std::cout << "Enter the radius and height of your cylinder: " << std::endl;
        double radius, height;
        std::cin >> radius >> height;
        double cylinderArea = 2 * M_PI * radius * (radius + height);
        std::cout << "The area of your cylinder is: " << cylinderArea << std::endl;
        break;
    }
    }
    return 0;
}
#include <iostream>

// Function to add numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide numbers
double divide(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero\n";
        return 0;
    }
    return a / b;
}

int main() {
    // Hard-coded student information
    std::cout << "Name: Umme Aiman\n";
    std::cout << "Student ID: BC230403969\n";

    int choice;
    char continueChoice;

    do {
        // Display menu
        std::cout << "\nSelect an operation:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        double result = 0;
        double num;
        int count;

        switch (choice) {
            case 1:
            case 2:
            case 3:
                // Ask for the number of operands
                std::cout << "How many numbers do you want to " << ((choice == 1) ? "add" : (choice == 2) ? "subtract" : "multiply") << "? ";
                std::cin >> count;

                // Input numbers and perform operation
                for (int i = 0; i < count; ++i) {
                    std::cout << "Enter number " << i + 1 << ": ";
                    std::cin >> num;
                    if (i == 0)
                        result = num;
                    else
                        result = (choice == 1) ? add(result, num) : (choice == 2) ? subtract(result, num) : multiply(result, num);
                }
                std::cout << "Result: " << result << std::endl;
                break;

            case 4:
                // Ask for the number of operands
                std::cout << "How many numbers do you want to divide? ";
                std::cin >> count;

                // Input numbers and perform division
                for (int i = 0; i < count; ++i) {
                    std::cout << "Enter number " << i + 1 << ": ";
                    std::cin >> num;
                    if (i == 0)
                        result = num;
                    else {
                        if (num == 0) {
                            std::cout << "Error: Division by zero\n";
                            result = 0;
                            break;
                        } else {
                            result = divide(result, num);
                        }
                    }
                }
                std::cout << "Result: " << result << std::endl;
                break;

            case 5:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 5) {
            std::cout << "Do you want to continue? (y/n): ";
            std::cin >> continueChoice;
        }
    } while (choice != 5 && (continueChoice == 'y' || continueChoice == 'Y'));

    return 0;
}

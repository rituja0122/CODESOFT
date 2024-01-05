#include <iostream>

int main() {
    char op;
    double num1, num2, result;
    bool continueCalculation = true;

    while (continueCalculation) {
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> op;

        std::cout << "Enter two numbers: ";
        std::cin >> num1 >> num2;

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    std::cout << "Error! Division by zero is not allowed." << std::endl;
                    continue;
                }
                break;
            default:
                std::cout << "Error! Invalid operator." << std::endl;
                continue;
        }

        std::cout << "Result: " << result << std::endl;

        char choice;
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            continueCalculation = false;
        }
    }

    return 0;
}


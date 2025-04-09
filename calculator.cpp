#include <iostream>
#include <cstdlib> // for system("cls") or system("clear")

using namespace std;

int main() {
    double num1, num2;
    char choice;

    cout << "==== Simple C++ Calculator ====\n";
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    do {
        char operation;

        cout << "\nSelect Operation:\n";
        cout << "+ : Addition\n";
        cout << "- : Subtraction\n";
        cout << "* : Multiplication\n";
        cout << "/ : Division\n";
        cout << "% : Modulus\n";
        cout << "C : Clear screen\n";
        cout << "Enter your choice: ";
        cin >> operation;

        switch (operation) {
            case '+':
                cout << "Result: " << (num1 + num2) << endl;
                break;
            case '-':
                cout << "Result: " << (num1 - num2) << endl;
                break;
            case '*':
                cout << "Result: " << (num1 * num2) << endl;
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << (num1 / num2) << endl;
                else
                    cout << "Error: Division by zero!" << endl;
                break;
            case '%':
                if ((int)num2 != 0)
                    cout << "Result: " << ((int)num1 % (int)num2) << endl;
                else
                    cout << "Error: Modulus by zero!" << endl;
                break;
            case 'C':
            case 'c':
                system("cls"); // Use "clear" if you're on Linux/Mac
                cout << "Screen cleared.\n";
                break;
            default:
                cout << "Invalid operation!" << endl;
        }

        cout << "\nWhat would you like to do next?" << endl;
        cout << "Y - Perform another operation on the same numbers" << endl;
        cout << "N - Exit the calculator" << endl;
        cout << "X - Change the numbers" << endl;
        cout << "Enter your choice (Y/N/X): ";
        cin >> choice;

        if (choice == 'X' || choice == 'x') {
            cout << "\nEnter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
        }

    } while (choice == 'Y' || choice == 'y' || choice == 'X' || choice == 'x');

    cout << "\nThank you for using the calculator!\n";
    return 0;
}
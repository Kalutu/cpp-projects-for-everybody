#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char op;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;

        case '-':
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;

        case '*':
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;

        case '/':
            if (num2 == 0) {
                cout << "Error: division by zero" << endl;
            } else {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endl;
            }
            break;

        default:
            cout << "Invalid operator" << endl;
            break;
    }

    return 0;
}

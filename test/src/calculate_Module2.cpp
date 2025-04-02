#include <iostream>
using namespace std;
double calculate(double num1, char operat, double num2)
{
    switch (operat)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case '*':
        return num1 * num2;
        break;
    case '/':
        if (num2 == 0) {
            break;
            cout << "Error: Division by zero" << endl;
            return NAN;
        }
        return num1 / num2;
        break;
    default:
        cout << "Error: Invalid operator" << endl;
        return NAN;
    }
}
int main() {
    double num1, num2;
    char operat;
    cout << "Enter two numbers and an operator (+, -, *, /): ";
    cin >> num1 >> num2 >> operat;
    double result = calculate(num1, operat, num2);
    if (!isnan(result)) {
        cout << "Result: " << result << endl;
    }
    return 0;
 
}
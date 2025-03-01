#include <iostream>
using namespace std;

int getChoice();
pair<double, double> getNumbers();
double addition(double x, double y);
double subtraction(double x, double y);
double division(double x, double y);
double multiplication(double x, double y);

int main() {
    cout << "Welcome to your calculator" << endl;
    int choice;
    do {
        choice = getChoice();
        if (choice == 0) break;

        pair<double, double> numbers = getNumbers();
        double result;

        switch (choice) {
            case 1:
                result = addition(numbers.first, numbers.second);
                break;
            case 2:
                result = subtraction(numbers.first, numbers.second);
                break;
            case 3:
                result = multiplication(numbers.first, numbers.second);
                break;
            case 4:
                if (numbers.second == 0) {
                    cout << "Cannot divide by 0!" << endl;
                    continue;
                } else {
                    result = division(numbers.first, numbers.second);
                }
                break;
            default:
                cout << "Invalid choice!" << endl;
                return 1;
        }
        cout << "Result: " << result << endl;
    } while (choice != 0);

    return 0;
}

int getChoice() {
    int choice;
    cout << "\nChoose operation: \n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n0. Quit\n";
    cout << "Enter choice (0-4): ";

    while (!(cin >> choice) || choice < 0 || choice > 4) {
        cout << "Invalid input! Enter a number between 0-4: ";
        cin.clear();  
        cin.ignore(10000, '\n');  
    }
    return choice;
}

pair<double, double> getNumbers() {
    double x, y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    return {x, y};
}

double addition(double x, double y) {
    return x + y;
}

double subtraction(double x, double y) {
    return x - y;
}

double division(double x, double y) {
    return x / y;
}

double multiplication(double x, double y) {
    return x * y;
}

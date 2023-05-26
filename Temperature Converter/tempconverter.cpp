#include <iostream>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    double temperature;
    char choice;

    cout << "Temperature Converter" << endl;
    cout << "---------------------" << endl;

    do {
        cout << "Enter the temperature: ";
        cin >> temperature;

        cout << "Select the conversion: " << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        double convertedTemperature;
        switch (choice) {
            case '1':
                convertedTemperature = celsiusToFahrenheit(temperature);
                cout << temperature << " degrees Celsius is equal to " << convertedTemperature << " degrees Fahrenheit." << endl;
                break;
            case '2':
                convertedTemperature = fahrenheitToCelsius(temperature);
                cout << temperature << " degrees Fahrenheit is equal to " << convertedTemperature << " degrees Celsius." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "Do you want to convert another temperature? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;

    return 0;
}


#include <iostream>
#include <iomanip>
#include "ModulesNikolenko.h"

using namespace std;

int main() {
    cout << "(C) Nikolenko S. S., 2026" << endl;

    double x, y, z;
    int a, b;

    cout << "Enter values for x, y, z (for S calculation):" << endl;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "z = "; cin >> z;

    cout << "\nEnter integer values for a and b (for logical expression):" << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    bool logicResult = (a + 1 <= b);


    cout << "Logical expression (a + 1 <= b) is: " << boolalpha << logicResult << endl;

    cout << "Decimal (dec):\t\ta = " << dec << a << ", b = " << b << endl;
    cout << "Hexadecimal (hex):\ta = " << hex << a << ", b = " << b << endl;

    cout << dec;

    double s = s_calculation(x, y, z);
    cout << "Result of function S = " << s << endl;

    system("pause");
    return 0;
}

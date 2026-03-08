#include <iostream>
#include <iomanip>
#include <cmath>
#include "ModulesNikolenko.h"

using namespace std;

void runTestCase(int tc_id, double x, double y, double z, double expected) {
    double actual = s_calculation(x, y, z);

    cout << "TC-" << tc_id << " | x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << "Очікувано: " << expected << " | Фактично: " << actual << " | Статус: ";

    if (isinf(expected) && isinf(actual)) {
        cout << "passed" << endl;
    } else if (abs(actual - expected) < 0.01) {
        cout << "passed" << endl;
    } else {
        cout << "failed" << endl;
    }
;
}

int main() {
    cout << "Протокол модульного тестування функцiї s_calculation" << endl;

    runTestCase(1, 2.0, 1.0, 1.5708, -3.0389);
    runTestCase(2, 0.0, 0.0, 1.5708, -1.5708);
    runTestCase(3, 1.0, 2.0, 0.5, -1.0561);
    runTestCase(4, 3.0, -2.0, 0.5, -10.2810);
    runTestCase(5, 1.0, 1.0, 0.0, -INFINITY);

    system("pause");
    return 0;
}

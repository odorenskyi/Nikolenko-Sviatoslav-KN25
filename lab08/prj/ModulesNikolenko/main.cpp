#include <cmath>
#include <iostream>

using namespace std;


double s_calculation(double x, double y, double z) {

    if (sin(z) == 0.0) {
        return -INFINITY;
    }

    double term1 = 0.5 * pow(x, 2);
    double term2 = sqrt(abs(pow(y + z, 2) - pow(x, 5)));
    double term3 = log(abs(sin(z)));

    return term1 - term2 - term3;
}

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double s;

    while (cin >> s){
        double r1, r2, r3, r4;
        
        r1 = (s / 2.0) * sqrt(3.0);
        r2 = sqrt(3.0) / (2.0 + sqrt(3.0)) * s;
        r3 = sqrt(3.0) / 4.0 * s;
    
        double a = 5.0 / 3.0;
        double b = 7.0 * s / (sqrt(3.0));
        double c = -1.0 * 7.0 / 4.0 * s * s;

        r4 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);

        cout << fixed << setprecision(10) << r1 << " " << r2 << " " << r3 << " " << r4 << endl;
    }

    return 0;
}

//  5    2        7s             7   2
// ——— r4   +   —————— r4   -   ——— s   = 0
//  3           sqrt(3)          4

//  a              b             c
// quadratic formula
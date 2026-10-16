#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    long long k = 6;
    int found = 0;

    while (found < 10){
        long long n = (-1 + sqrt(1 + 8 * k * k)) / 2;
        
        if (2 * k * k == n * (n + 1)){
            cout << setw(10) << k << setw(10) << n << endl;
            found++;
        }
        k++;
    }

    return 0;
}

// 1 ~ (k - 1)          =         (k + 1) ~ n
// (k - 1) * k / 2      =         [n * (n + 1) / 2] - [k * (k + 1) / 2]
// (k - 1) * k          =         n * (n + 1) - k * (k + 1)
// k^2 - k              =         n^2 + n - k^2 - k
// 2k^2                 =         n^2 + n

// n = 


// n * (n + 1) / 2


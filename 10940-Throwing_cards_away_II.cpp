#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;

    while (cin >> n && n){
        int p = 0;

        while (pow(2, p + 1) < n){
            p += 1;
        }

        int q = pow(2, p);

        if (n == q){
            cout << n << endl;
        }else{
            cout << 2 * (n - q) << endl;
        }
    }

    return 0;
}

// 1  1
// 2 [2]
// 3  2
// 4 [4]
// 5  2
// 6  4
// 7  6
// 8 [8]
// 9  2

// when n is not a power of 2 : 2 * (n - 2^p)
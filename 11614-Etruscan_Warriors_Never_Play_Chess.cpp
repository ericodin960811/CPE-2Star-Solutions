#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    long long n;
    cin >> t;

    while (t--){
        cin >> n;

        long long k = floor((-1 + sqrt(1 + 8 * n)) / 2);
        cout << k << endl;
    }

    return 0;
}

// n = k * (k + 1) / 2
// 2 * n = k^2 + k
// k^2 + k - 2n <= 0 (max k)

// k <= (-1 + sqrt(1 - 4 * (-2n))) / 2
//   <= (-1 + sqrt(1 + 8n)) / 2
//   = floor((-1 + sqrt(1 + 8n)) / 2)
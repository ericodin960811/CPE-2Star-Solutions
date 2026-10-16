#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    
    while (cin >> n && n){
        long long sum = 0;
        
        for (long long l = 1, r; l <= n; l = r + 1){
            r = n / (n / l);
            long long k = n / l;
            sum += (l + r) * (r - l + 1) / 2 * k;
        }
        
        cout << sum - 1 << endl;
    }
    
    return 0;
}
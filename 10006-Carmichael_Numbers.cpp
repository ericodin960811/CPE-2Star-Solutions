#include <iostream>
using namespace std;

bool isPrime[65005];

void genPrime(){
    fill(isPrime, isPrime + 65005, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i * i < 65005; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < 65005; j += i){
                isPrime[j] = false;
            }
        }
    }
}

long long PowAndMod(long long a, long long n, long long m){
    long long res = 1; // result
    
    a %= m;
    while (n > 0){
        if (n % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        n /= 2;
    }
    
    return res;
}

int main() {
    genPrime();
    
    int n;
    
    while (cin >> n && n){
        bool isCarmichael = true;
        
        if (isPrime[n]){
            cout << n << " is normal." << endl;
        }else{
            for (int a = 2; a < n; ++a){
                if (PowAndMod(a, n, n) != a){
                    isCarmichael = false;
                    break;
                }
            }
            
            if (isCarmichael){
                cout << "The number " << n << " is a Carmichael number." << endl;
            }else{
                cout << n << " is normal." << endl;
            }
        }
    }

    return 0;
}
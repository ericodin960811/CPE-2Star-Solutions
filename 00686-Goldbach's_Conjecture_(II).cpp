#include <iostream>
using namespace std;

int main(){
    bool isPrime[33000];
    
    fill(isPrime, isPrime + 33000, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i * i < 33000; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < 33000; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    int n;
    while (cin >> n && n){
        int counter = 0;
        for (int i = 2; i <= n / 2; ++i){
            if (isPrime[i] && isPrime[n - i]){
                counter++;
            }
        }
        cout << counter << endl;
    }
    
    return 0;
}
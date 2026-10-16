#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    bool isPrime[33000];
    fill(isPrime, isPrime + 33000, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= 33000; ++i){
        for (int j = i; j <= 33000; j += i){
            isPrime[j] = false;
        }
    }
    for (int i=0; i<=100; ++i){
        if (isPrime[i]){
            cout << i << " ";
        }
    }
    cout << isPrime[23];
    
    string line;
    while (getline(cin, line) && line != "0"){
        int sum = 1;
        int n;
        int t;
        stringstream ss(line);
        while (ss >> n >> t){
            if (t != 0){
                int temp = 1;
                for (int i = 0; i < t; ++i){
                    temp *= n;
                }
                sum *= temp;
            }
        }
        sum -= 1;
        
        
    }

    return 0;
}
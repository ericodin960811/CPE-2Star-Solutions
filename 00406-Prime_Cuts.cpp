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
        if (isPrime[i]){
            for (int j = i * i; j <= 33000; j += i){
                isPrime[j] = false;
            }
        }
    }
    int prime[33000];
    int j = 0;
    for (int i = 0; i < 33000; ++i){
        if (isPrime[i] == true){
            prime[j] = i;
            j++;
        }
    }
    
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
        
        for (int i = j - 1; i >= 0; i--){
            int power = 0;
            while (sum % prime[i] == 0){
                power++;
                sum /= prime[i];
            }
            if (power > 0){
                cout << prime[i] << " " << power << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
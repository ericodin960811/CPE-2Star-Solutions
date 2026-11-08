#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string s;
    bool isPrime[1045];

    fill(isPrime, isPrime + 1045, true);

    for (int i = 2; i * i < 1045; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < 1045; j += i){
                isPrime[j] = false;
            }
        }
    }

    while (cin >> s){
        int sum = 0;

        for (char c : s){
            if (isupper(c)){
                sum += c - 'A' + 27;
            }else{
                sum += c - 'a' + 1;
            }
        }

        if (isPrime[sum]){
            cout << "It is a prime word." << endl;
        }else{
            cout << "It is not a prime word." << endl;
        }
    }

    return 0;
}
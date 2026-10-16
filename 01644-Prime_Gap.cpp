#include <iostream>
#include <vector>
using namespace std;

bool isPrime[1299710];
vector <int> Prime;

void genPrime(){
    fill(isPrime, isPrime + 1299710, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i * i < 1299710; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < 1299710; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= 1299709; ++i){
        if (isPrime[i]){
            Prime.push_back(i);
        }
    }
}

int main(){
    genPrime();
    
    int k;
    
    while (cin >> k && k){
        if (isPrime[k]){
            cout << "0" << endl;
        }else{
            int index = 0;
            
            for (int i = 0; i <= 100000; ++i){
                if (Prime[i] < k){
                    index = i;
                }else{
                    break;
                }
            }
            cout << Prime[index + 1] - Prime[index] << endl;
        }
    }
    
    return 0;
}
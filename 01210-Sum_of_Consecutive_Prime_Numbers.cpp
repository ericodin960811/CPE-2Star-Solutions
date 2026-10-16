#include <iostream>
#include <vector>
using namespace std;

bool isPrime[10005];
vector <int> Prime;

void genPrime(){
    fill(isPrime, isPrime + 10005, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (int i = 2; i * i < 10005; ++i){
        if (isPrime[i]){
            for (int j = i * i; j < 10005; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i < 10005; ++i){
        if (isPrime[i]){
            Prime.push_back(i);
        }
    }
}

int main(){
    genPrime();
    int n;
    
    while (cin >> n && n){
        int times = 0;
        
        for (int i = 0; i < Prime.size(); ++i){
            if (Prime[i] > n) break;
            
            int sum = 0;
            for (int j = i; j < Prime.size(); ++j){
                sum += Prime[j];
                if (sum > n) break;
                
                if (sum == n){
                    times++;
                    break;
                }
            }
        }
        
        cout << times << endl;
    }
    
    return 0;
}
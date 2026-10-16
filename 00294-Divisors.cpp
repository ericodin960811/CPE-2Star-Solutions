#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){
    bool prime[32000];
    fill(prime, prime + 32000, true);
    prime[0] = prime[1] = false;
    
    for (int i=2; i*i<32000; ++i){
        if (prime[i]){
            for (int j=i*i; j<32000; j+=i){
                prime[j] = false;
            }
        }
    }
    
    vector <int> Prime;
    for (int i=2; i<32000; ++i){
        if (prime[i] == true){
            Prime.push_back(i);
        }
    }
    
    int t;
    int l, h;
    cin >> t;
    while (t--){
        cin >> l >> h;
        
        int MaxNum = 0;
        int MaxDivisor = 0;
        
        for (int i=l; i<=h; ++i){
            int num = i;
            map <int, int> Map;
            int divisor = 1;
            
            for (int p : Prime){
                if (p * p > num){
                    break;
                }
                while (num % p == 0){
                    Map[p]++;
                    num /= p;
                }
            }
            if (num > 1){
                Map[num]++;
            }
            
            for (auto a : Map){
                divisor *= (a.second + 1);
            }
            
            if (divisor > MaxDivisor){
                MaxDivisor = divisor;
                MaxNum = i;
            }
        }
        cout << "Between " << l << " and " << h << ", " << MaxNum << " has a maximum of " << MaxDivisor << " divisors." << endl;
    }
    
    return 0;
}
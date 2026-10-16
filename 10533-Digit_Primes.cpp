#include <iostream>
using namespace std;

bool Prime[1000001];
int DP[1000001] = {0};
int Prefix[1000001] = {0};

int main(){
    // 建質數表用篩法
    fill(Prime, Prime + 1000001, true);
        
    Prime[0] = false; Prime[1] = false;
    for (int i=2; i*i<=1000000; ++i){
        if (Prime[i]){
            for (int j=i*i; j<=1000000; j+=i) // i*i就不會遇到已經改過的
            Prime[j] = false;
        }
    }
    
    // DigitPrime
    for (int i=2; i<=1000000; ++i){
        if (Prime[i] == true){
            int num = i;
            int sum = 0;
            
            while (num > 0){
                sum += num % 10;
                num /= 10;
            }
            
            if (Prime[sum]){
                DP[i] = 1;
            }
        }
    }
    
    for (int i=2; i<=1000000; ++i){
        Prefix[i] = DP[i] + Prefix[i-1];
    }
    
    int n, t1, t2;
    cin >> n;
    while (n--){
        cin >> t1 >> t2;
        cout << Prefix[t2] - Prefix[t1-1] << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int coins[6] = {1, 5, 10, 25, 50};
    int dp[7500] = {1};
    
    for (int i=0; i<5; ++i){ // coins
        for (int j=coins[i]; j<7500; ++j){ // dp
            dp[j] += dp[j-coins[i]];
        }
    }
    
    while (cin >> n){
        cout << dp[n] << endl;
    }
    
    return 0;
}
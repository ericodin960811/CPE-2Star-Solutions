#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int dp[55];
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 55; ++i){
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    
    while (cin >> n && n){
        cout << dp[n] << endl;
    }
    
    return 0;
}

// |
// || =
// |= =| |||
// |||| == |=| ||= =||
// fib
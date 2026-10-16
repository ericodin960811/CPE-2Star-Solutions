#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t, n, g, mw;
    cin >> t;
    while (t--){
        cin >> n;
        vector <int> Price(n), Weight(n);
        
        for (int i=0; i<n; ++i){
            cin >> Price[i] >> Weight[i];
        }
        cin >> g;
        
        int total = 0;
        while (g--){
            cin >> mw;
            vector <int> dp (mw + 1, 0);
            
            for (int i=0; i<n; ++i){
                for (int j=mw; j>=Weight[i]; j--){
                    dp[j] = max(dp[j], dp[j - Weight[i]] + Price[i]);
                }
            }
            total += dp[mw];
        }
        cout << total << endl;
    }
    
    return 0;
}
// 難
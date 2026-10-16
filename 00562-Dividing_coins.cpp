#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, m;
    cin >> t;
    while (t--){
        cin >> m;
        vector <int> Money(m);
        int sum = 0;
        
        for (int i=0; i<m; ++i){
            cin >> Money[i];
            sum += Money[i];
        }
        
        vector <int> dp (sum/2 + 1, 0);
        
        for (int i=0; i<m; ++i){
            for (int j=sum/2; j>=Money[i]; j--){
                dp[j] = max(dp[j], dp[j - Money[i]] + Money[i]);
            }
        }
        cout << (sum - dp[sum/2]) - dp[sum/2] << endl;
    }
    
    return 0;
}
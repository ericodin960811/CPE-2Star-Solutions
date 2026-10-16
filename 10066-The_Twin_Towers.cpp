#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n1, n2;
    int counter = 0;
    
    while (cin >> n1 >> n2 && (n1 != 0 || n2 != 0)){
        vector <int> V1(n1);
        vector <int> V2(n2);
        
        for (int i=0; i<n1; ++i){
            cin >> V1[i];
        }
        for (int i=0; i<n2; ++i){
            cin >> V2[i];
        }
        
        int dp[105][105] = {0};
        
        for (int i=1; i<=n1; ++i){
            for (int j=1; j<=n2; ++j){
                if (V1[i-1] == V2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        counter++;
        cout << "Twin Towers #" << counter << endl;
        cout << "Number of Tiles : " << dp[n1][n2] << endl;
    }
    
    return 0;
}
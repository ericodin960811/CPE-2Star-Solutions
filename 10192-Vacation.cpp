#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string s1, s2;
    int counter = 0;
    
    while (getline(cin, s1) && s1 != "#"){
        getline(cin, s2);
        int dp[105][105] = {0};
        
        for (int i=1; i<=s1.size(); ++i){
            for (int j=1; j<=s2.size(); ++j){
                if (s1[i-1] == s2[j-1]){ // 字一樣的話，就拿左上加一
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{ // 不一樣
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 就拿上或左的max
                }
            }
        }
        
        counter++;
        cout << "Case #" << counter << ": you can visit at most " << dp[s1.size()][s2.size()] << " cities." << endl;
    }
    
    return 0;
}
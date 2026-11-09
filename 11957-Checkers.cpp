#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int t, n;
    cin >> t;

    for (int k = 1; k <= t; ++k){
        cin >> n;
        cin.ignore();

        vector <vector<char>> Board(n);
        string line;
        vector <vector<int>> dp(n, vector <int>(n, 0));
        int wr, wc;
        int counter = 0;

        for (int i = 0; i < n; ++i){
            getline(cin, line);
            for (int j = 0; j < n; ++j){
                if (line[j] == 'W'){
                    wr = i;
                    wc = j;
                }
                Board[i].push_back(line[j]);
            }
        }

        dp[wr][wc] = 1;

        // push dp
        for (int r = wr; r >= 0; --r){
            for (int c = 0; c < n; ++c){
                if (dp[r][c] == 0) continue;
                // up left
                if (r - 1 >= 0 && c - 1 >= 0 && Board[r - 1][c - 1] == '.'){
                    dp[r - 1][c - 1] = (dp[r - 1][c - 1] + dp[r][c]) % 1000007;
                }
                if (r - 2 >= 0 && c - 2 >= 0 && Board[r - 1][c - 1] == 'B' && Board[r - 2][c - 2] == '.'){
                    dp[r - 2][c - 2] = (dp[r - 2][c - 2] + dp[r][c]) % 1000007;
                }

                // up right
                if (r - 1 >= 0 && c + 1 < n && Board[r - 1][c + 1] == '.'){
                    dp[r - 1][c + 1] = (dp[r - 1][c + 1] + dp[r][c]) % 1000007;
                }
                if (r - 2 >= 0 && c + 2 < n && Board[r - 1][c + 1] == 'B' && Board[r - 2][c + 2] == '.'){
                    dp[r - 2][c + 2] = (dp[r - 2][c + 2] + dp[r][c]) % 1000007;
                }
            }
        }

        for (int i = 0; i < n; ++i){
            counter += dp[0][i];
        }
        
        cout << "Case " << k << ": " << counter % 1000007 << endl;;
    }

    return 0;
}
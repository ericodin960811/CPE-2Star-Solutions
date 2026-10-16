#include <iostream>
#include <string>
using namespace std;

char Map[105][105];
int counter = 0;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int r, int c, int MaxR, int MaxC){
    if ((r < 0 || r > MaxR) && (c > 0 || c > MaxC)){
        return;
    }
    if (Map[r][c] == '0'){
        counter++;
        Map[r][c] = '1';
        for (int i = 0; i < 4; ++i){
            dfs(r + dr[i], c + dc[i], MaxR, MaxC);
        }
    }else{
        return;
    }
}

int main(){
    int t, i, j;
    string line;
    
    cin >> t;
    while (t--){
        for (int i = 0; i < 105; ++i){
            for (int j = 0; j < 105; ++j){
                Map[i][j] = '1';
            }
        }
        
        cin >> i;
        cin >> j;
        cin.ignore();
        counter = 0;
        
        int MaxR = 0;
        int MaxC = 0;
        while (getline(cin, line) && !line.empty()){
            for (int i = 0; i < line.size(); ++i){
                Map[MaxR][i] = line[i];
                MaxC = line.size() - 1;
            }
            MaxR++;
        }
        
        MaxR--;
        i--;
        j--;
         
        dfs(i, j, MaxR, MaxC);
        cout << counter << endl;
        if (t > 0){
            cout << endl;
        }
    }
    
    return 0;
}
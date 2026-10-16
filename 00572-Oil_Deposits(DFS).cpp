#include <iostream>
#include <string>
using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int counter;
char Map[105][105];

void dfs(int r, int c, int MaxR, int MaxC){
    if (r < 0 || r >= MaxR || c < 0 || c >= MaxC) return;
    if (Map[r][c] != '@') return;
    
    Map[r][c] = '.';
    
    for (int i = 0; i < 8; ++i){
        dfs(r + dr[i], c + dc[i], MaxR, MaxC);
    }
}

int main(){
    int row, col;
    string line;
    
    while (cin >> row >> col && row && col){
        cin.ignore();
        counter = 0;
        
        for (int i = 0; i < row; ++i){
            getline(cin, line);
            for (int j = 0; j < col; ++j){
                Map[i][j] = line[j];
            }
        }
        
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (Map[i][j] == '@'){
                    counter++;
                    dfs(i, j, row, col);
                }
            }
        }
        
        cout << counter << endl;
    }
    
    return 0;
}
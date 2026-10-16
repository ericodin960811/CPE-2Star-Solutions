#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    int row, col;
    string line;
    int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0}; // delta row
    int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1}; // delta column
    
    while (cin >> row >> col && row && col){
        cin.ignore();
        int counter = 0;
        char Map[105][105];
        queue <pair<int, int>> q;
        
        for (int i = 0; i < row; i++){
            getline(cin, line);
            for (int j = 0; j < col; ++j){
                Map[i][j] = line[j];
            }
        }
        
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (Map[i][j] == '@'){
                    counter++;
                    q.push({i, j});
                    Map[i][j] = '.';
                    
                    while (!q.empty()){
                        pair <int, int> temp = q.front();
                        int r = temp.first;
                        int c = temp.second;
                        q.pop();
                        
                        for (int d = 0; d < 8; ++d){ // direction
                            int nr = r + dr[d]; // new row
                            int nc = c + dc[d]; // new column
                            
                            if ((nr >= 0 && nr < row) && (nc >= 0 && nc < col) && Map[nr][nc] == '@'){
                                Map[nr][nc] = '.';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        cout << counter << endl;
    }
    
    return 0;
}
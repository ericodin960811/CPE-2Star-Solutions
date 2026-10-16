#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int m, n;
    int i, j;
    
    while (cin >> n >> m && (n || m)){
    
        vector <int> adj[105];
        int inDegree[105] = {0};
        queue <int> q;
        
        for (int a=0; a<m; ++a){
            cin >> i >> j;
            adj[i].push_back(j); // 我卡住了誰（這樣比較簡單）
            inDegree[j]++;
        }
        
        for (int b=1; b<=n; ++b){
            if (inDegree[b] == 0){
                q.push(b);
            }
        }
        
        while (!q.empty()){
            int num = q.front();
            cout << num;
            q.pop();
            
            for (int z : adj[num]){
                inDegree[z]--;
                if (inDegree[z] == 0){
                    q.push(z);
                }
            }
            
            if (!q.empty()){
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
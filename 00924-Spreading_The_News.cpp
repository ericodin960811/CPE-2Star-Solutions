#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int e, t, n, friendId;
    string line;
    vector <int> adj[2505];
    
    cin >> e;
    
    for (int i = 0; i < e; ++i){
        cin >> n;
        while (n--){
            cin >> friendId;
            adj[i].push_back(friendId);
        }
    }
    
    cin >> t;
    int start;
    
    for (int i = 0; i < t; ++i){
        cin >> start;
        
        int dist[2505]; // 第幾天知道
        fill (dist, dist + 2505, -1);
        int dailyCount[2505] = {0};
        queue <int> q;

        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()){
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]){
                if (dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    dailyCount[dist[v]]++;
                    q.push(v);
                }
            }
        }
        
        int maxBoom = 0;
        int firstDay = 0;
        
        for (int d = 1; d < e; ++d){
            if (dailyCount[d] > maxBoom){
                maxBoom = dailyCount[d];
                firstDay = d;
            }
        }
        
        if (maxBoom == 0 || firstDay == 0){
            cout << "0" << endl;
        }else{
            cout << maxBoom << " " << firstDay << endl;
        }
    }
    
    return 0;
}
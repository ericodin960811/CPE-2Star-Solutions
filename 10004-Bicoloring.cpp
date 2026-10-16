#include <iostream>
#include <map>
#include <vector>
using namespace std;

int color[205]; // 0 1 2
map <int, vector<int>> Map;
bool isBicolorable;

void dfs(int u, int c){
    color[u] = c;
    
    for (int v : Map[u]){
        if (color[v] == 0){
            dfs(v, 3 - c);
        }else if (color[v] == c){
            isBicolorable = false;
        }
    }
}

int main(){
    int n, l;
    int a, b;
    
    while (cin >> n && n){
        cin >> l;
        
        isBicolorable = true;
        for (int i = 0; i < n; ++i){
            color[i] = 0;
            Map[i].clear();
        }
        
        for (int i = 0; i < l; ++i){
            cin >> a;
            cin >> b;
            
            Map[a].push_back(b);
            Map[b].push_back(a);
        }
        
        dfs(0, 1);
        
        if (isBicolorable){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    
    return 0;
}
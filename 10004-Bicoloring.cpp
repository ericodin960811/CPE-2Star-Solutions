#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, int c, vector <vector<int>>& Graph, vector<int>& Color){
    Color[u] = c;

    for (int v : Graph[u]){
        if (Color[v] == 0){
            if (!dfs(v, 3 - c, Graph, Color)){
                return false;
            }
        }else{
            if (Color[u] == Color[v]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n, m, node1, node2;

    while (cin >> n && n){
        cin >> m;

        vector <vector<int>> Graph(n);
        vector <int> Color(n, 0); // n 0's

        while (m--){
            cin >> node1 >> node2;
            Graph[node1].push_back(node2);
            Graph[node2].push_back(node1);
        }

        if(dfs(0, 1, Graph, Color)){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
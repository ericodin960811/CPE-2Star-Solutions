#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int counter = 0;
    int a, b;
    int dist[105][105];
    bool appeared[105] = {false};
    
    while (cin >> a >> b && (a && b)){
        fill(appeared, appeared + 105, false);
        for (int i = 0; i < 105; ++i){
            for (int j = 0; j < 105; ++j){
                if (i == j){
                    dist[i][j] = 0;
                }else{
                    dist[i][j] = 999;
                }
                appeared[a] = true;
                appeared[b] = true;
            }
        }
        
        dist[a][b] = 1;
        while (cin >> a >> b && (a && b)){
            dist[a][b] = 1;
            appeared[a] = true;
            appeared[b] = true;
        }
        
        for (int k = 0; k < 105; ++k){
            for (int i = 0; i < 105; ++i){
                for (int j = 0; j < 105; ++j){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        double length = 0.0;
        double pair = 0.0;
        
        for (int i = 0; i < 105; ++i){
            for (int j = 0; j < 105; ++j){
                if (appeared[i] && appeared[j] && i != j){
                    length += dist[i][j];
                    pair++;
                }
            }
        }
        double ans = length / pair;
        
        counter++;
        cout << "Case " << counter << ": average length between pages = " << fixed << setprecision(3) << ans << " clicks" << endl;
    }
    
    return 0;
}
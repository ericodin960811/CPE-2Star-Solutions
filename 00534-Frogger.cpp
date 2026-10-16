#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct point{
    int x, y;
};

float getDist(point a, point b){
    float dist;
    dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    
    return dist;
}

int main(){
    int counter = 0;
    int n;
    
    while (cin >> n && n != 0){
        vector <point> Points(n);
        
        for (int i = 0; i < n; ++i){
            cin >> Points[i].x >> Points[i].y;
        }
        
        float dist[205][205];
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                dist[i][j] = getDist(Points[i], Points[j]);
            }
        }
        
        for (int k = 0; k < n; ++k){
            for (int i = 0; i < n; ++i){
                for (int j = 0; j < n; ++j){
                    dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
        }
        
        counter++;
        cout << "Scenario #" << counter << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << dist[0][1] << endl << endl;
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, s;
    
    while (cin >> t && t){
        vector <int> stations;
        
        while (t--){
            cin >> s;
            stations.push_back(s);
        }
        
        sort(stations.begin(), stations.end());
        
        bool isPosible = true;
        
        // begin
        if (stations[0] > 200){
            isPosible = false;
        }
        // end
        if (stations[stations.size() - 1] < 1322){
            isPosible = false;
        }
        // mid
        if (isPosible){
            for (int i=0; i<stations.size() - 1; ++i){
                if (stations[i + 1] - stations[i] > 200){
                    isPosible = false;
                }
            }
        }
        
        if (isPosible){
            cout << "POSSIBLE" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}
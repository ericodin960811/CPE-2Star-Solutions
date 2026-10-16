#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, n, m;
    string dna;
    bool first = true;
    cin >> t;
    
    while (t--){
        if (!first){
            cout << endl;
        }else{
            first = false;
        }
        vector <string> DNAs;
        vector <int> counters;
        int Max = 0;
        
        cin >> n >> m;
        while (m--){
            cin >> dna;
            int counter = 0;
            
            DNAs.push_back(dna);
            for (int i = 0; i < n; ++i){
                for (int j = i + 1; j < n; ++j){
                    if (dna[i] > dna[j]){
                        counter++;
                    }
                }
            }
            counters.push_back(counter);
            Max = max(Max, counter);
        }
        
        for (int i = 0; i <= Max; ++i){
            for (int j = 0; j < counters.size(); ++j){
                if (counters[j] == i){
                    cout << DNAs[j] << endl;
                }
            }
        }
    }
    
    return 0;
}
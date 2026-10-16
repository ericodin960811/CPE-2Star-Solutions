#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, num;
    
    while (cin >> n){
        vector <vector <int>> Vec (n, vector <int> (n));
    
        for (int i=0; i<n; ++i){
            for (int j=0; j<n; ++j){
                cin >> num;
                Vec[i][j] = num;
            }
        }
        
        int MaxAns = -2100000000;
        
        for (int i=0; i<n; ++i){
            vector <int> Compress (n);
            
            for (int j=i; j<n; ++j){
                for (int k=0; k<n; ++k){
                    Compress[k] += Vec[j][k];
                }
                
                int MaxSum = -2100000000;
                int curr = 0;
                
                for (int k=0; k<n; ++k){
                    curr += Compress[k];
                    MaxSum = max(MaxSum, curr);
                    if (curr < 0){
                        curr = 0;
                    }
                }
                MaxAns = max(MaxAns, MaxSum);
            }
        }
        cout << MaxAns << endl;
    }
}
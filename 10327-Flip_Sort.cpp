#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t, n;
    
    while (cin >> t){
        vector <int> Nums;
        int counter = 0;
        
        while (t--){
            cin >> n;
            Nums.push_back(n);
        }
        
        for (int i=0; i<Nums.size()-1; ++i){
            for (int j=i+1; j<Nums.size(); ++j){
                if (Nums[i] > Nums[j]){
                    // cout << i << '>' << j << endl;
                    counter++;
                }
            }
        }
        cout << "Minimum exchange operations : " << counter << endl;
    }
    
    return 0;
}
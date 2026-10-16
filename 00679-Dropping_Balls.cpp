#include <iostream>
using namespace std;

int main(){
    int t, D, I;
    cin >> t;
    
    while (t--){
        cin >> D >> I;
        
        int pos = 1; // node
        
        for (int d = 0; d < D - 1; ++d){
            if (I % 2 != 0){ // left
                pos *= 2;
                I = (I + 1) / 2;
            }else{
                pos = pos * 2 + 1;
                I /= 2;
            }
        }
        cout << pos << endl;
    }
    
    return 0;
}
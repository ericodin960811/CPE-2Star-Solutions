#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int row, col;
    
    while (cin >> row >> col && row && col){
        int knight = 0;
        int Min = min(row, col);
        int Max = max(row, col);
        
        if (Min == 1){
            knight = Max;
        }else if (Min == 2){
            knight = (Max / 4) * 4;
            if (Max % 4 == 1){
                knight += 2;
            }else if (Max % 4 > 1){
                knight += 4;
            }
        }else{
            knight = (row * col + 1) / 2;
        }
        
        cout << knight << " knights may be placed on a " << row << " row " << col << " column board." << endl;
    }
    
    return 0;
}
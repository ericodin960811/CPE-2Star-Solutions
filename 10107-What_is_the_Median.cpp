#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector <int> Vec;
    int n;

    while (cin >> n){
        auto it = upper_bound(Vec.begin(), Vec.end(), n); // upper_bound: binary search for the first num > n
        Vec.insert(it, n);

        if (Vec.size() % 2 == 1){
            cout << Vec[Vec.size() / 2] << endl;
        }else{
            cout << (Vec[Vec.size() / 2 - 1] + Vec[Vec.size() / 2]) / 2 << endl;
        }
    }

    return 0;
}
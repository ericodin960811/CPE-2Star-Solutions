#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector <int> Vec;
    int n;
    int counter = 0;

    while (cin >> n){
        counter++;
        Vec.push_back(n);
        sort(Vec.begin(), Vec.end());

        if (counter % 2 == 1){
            cout << Vec[counter / 2] << endl;
        }else{
            int num = (Vec[counter / 2 - 1] + Vec[counter / 2]) / 2;
            cout << num << endl;
        }
    }

    return 0;
}
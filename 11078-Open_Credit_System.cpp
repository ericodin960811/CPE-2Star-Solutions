#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    cin >> t;

    while (t--){
        cin >> n;

        vector <int> Grades(n);

        for (int i = 0; i < n; ++i){
            cin >> Grades[i];
        }

        int max_val = Grades[0];
        int max_amount = Grades[0] - Grades[1];

        for (int i = 1; i < n; ++i){
            max_amount = max(max_amount, max_val - Grades[i]);
            max_val = max(max_val, Grades[i]);
        }

        cout << max_amount << endl;
    }

    return 0;
}
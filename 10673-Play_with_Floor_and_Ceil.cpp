#include <iostream>
using namespace std;

int main(){
    int t, x, k;
    cin >> t;

    while (t--){
        cin >> x >> k;

        int floor = x / k;
        int ceil;

        if (x % k == 0){
                ceil = x / k;
            }else{
                ceil = x / k + 1;
            }

        for (int p = 0; p <= k; ++p){
            int temp = x - p * floor;

            if (temp % ceil == 0 && ceil != 0){
                cout << p << " " << temp / ceil << endl;
                break;
            }
        }
    }

    return 0;
}

// multiple solutions
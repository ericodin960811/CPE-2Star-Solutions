#include <iostream>
#include <string>
using namespace std;

int main(){
    int t, n;
    string s;

    cin >> t;

    while (t--){
        cin >> n;

        int counter = 0;
        int mask = 0;

        for (int i = 0; i < n; ++i){
            cin >> s;

            int curr_mask = 0;

            for (char c : s){
                curr_mask |= (1 << (c - 'a')); // union
            }

            if (i == 0){
                mask = curr_mask;
            }else{
                int temp = mask & curr_mask; // intersection

                if (temp == 0){ 
                    counter++;
                    mask = curr_mask;
                }else{
                    mask = temp;
                }
            }
        }
        cout << counter << endl;
    }

    return 0;
}

// bitmask
// 0000...0000
// zyxw...dcba
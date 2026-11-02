#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n;

    while (n--){
        vector <int> Num;
        cin >> m;

        for (int i = 0; i < m; ++i){
            cin >> a >> b;
            Num.push_back(a + b);
        }

        int carry = 0;
        int curr;

        for (int i = m - 1; i >= 0; i--){
            curr = carry + Num[i];
            Num[i] = curr % 10;
            carry = curr / 10;
        }

        if (carry > 0){
            cout << carry;
        }

        for (int i = 0; i < m; ++i){
                cout << Num[i];
        }
        cout << endl;
        
        if (n > 0){
            cout << endl;
        }
    }

    return 0;
}
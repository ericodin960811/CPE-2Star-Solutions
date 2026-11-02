#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    string line;
    int n1, n2;

    while (getline(cin, line)){
        stringstream ss(line);
        ss >> n1;

        if (ss >> n2){ // interval
            int counter = 0;

            for (int i = n1; i <= n2; ++i){
                int n = i;

                if (n % 4 == 2 || n % 4 == -2){
                    counter++;
                }
            }

            cout << counter << endl;
        }else{ // n = a^2 - b^2
            int abs_n = abs(n1);
            int r = abs_n % 4;

            if (r == 1 || r == 3){ // odd, couple number
                int a = (abs_n + 1) / 2;
                int b = (abs_n - 1) / 2;

                if (n1 < 0) swap(a, b);
                cout << a << " " << b << endl;
            }else if (r == 0){ // even, couple number
                int a = abs_n / 4 + 1;
                int b = abs_n / 4 - 1;

                if (n1 < 0) swap(a, b);
                cout << a << " " << b << endl;
            }else{ // r = 2
                if (n1 % 2 == 0) cout << "Bachelor Number." << endl;
                else cout << "Spinster Number." << endl;
            }
        }
    }    

    return 0;
}

// a^2 - b^2 = N
// (a + b)(a - b) = N
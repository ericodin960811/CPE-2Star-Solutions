#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int n, k, m, price;
    char c;
    string text;

    cin >> n;

    while (n--){
        int total_price = 0;
        vector <char> Char;
        vector <int> Price;

        cin >> k;
        
        for (int i = 0; i < k; ++i){
            cin >> c >> price;
            Char.push_back(c);
            Price.push_back(price);
        }

        cin >> m;
        cin.ignore();

        while (m--){
            getline(cin, text);
            for (char c : text){
                for (int i = 0; i < k; ++i){
                    if (c == Char[i]){
                        total_price += Price[i];
                        break;
                    }
                }
            }
        }
        double ans = total_price * 1.0 / 100;
        cout << fixed << setprecision(2) << ans << "$" << endl;
    }

    return 0;
}
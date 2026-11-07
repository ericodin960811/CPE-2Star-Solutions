#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main(){
    int t, m, n;
    string s;

    cin >> t;

    for (int i = 1; i <= t; ++i){
        cin >> m >> n;
        cin.ignore();

        vector <string> S1, S2;
        set <string> Set;

        for (int i = 0; i < m; ++i){
            getline(cin, s);
            S1.push_back(s);
        }

        for (int i = 0; i < n; ++i){
            getline(cin, s);
            S2.push_back(s);
        }

        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                Set.insert(S1[i] + S2[j]);
            }
        }

        cout << "Case " << i << ": " << Set.size() << endl;
    }

    return 0;
}
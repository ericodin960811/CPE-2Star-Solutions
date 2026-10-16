#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;

    while (cin >> s && s != "."){
        vector <int> pi (s.size(), 0);
        int j = 0;

        for (int i = 1; i < s.size(); ++i){
            // fail
            while (j > 0 && s[i] != s[j]){
                j = pi[j - 1];
            }

            // success
            if (s[i] == s[j]){
                j++;
            }

            pi[i] = j;
        }

        int match_len = pi[s.size() - 1];
        int period = s.size() - match_len;

        if (s.size() % period == 0){
            cout << s.size() / period << endl;
        }else{
            cout << 1 << endl;
        }
    }

    return 0;
}

// kmp version
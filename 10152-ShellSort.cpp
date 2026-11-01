#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int k, n;
    string name;

    cin >> k;

    while (k--){
        vector <string> Org, Req, Note;
        cin >> n;
        cin.ignore();

        for (int i = 0; i < n; ++i){
            getline(cin, name);
            Org.push_back(name);
        }

        for (int i = 0; i < n; ++i){
            getline(cin, name);
            Req.push_back(name);
        }

        int i = n - 1;
        int j = n - 1;
        int counter = 0;

        while (j >= 0){
            if (Req[i] == Org[j]){
                i--;
                j--;
            }else{
                counter++;
                j--;
            }
        }

        for (int i = counter - 1; i >= 0; i--){
            cout << Req[i] << endl;
        }
        // cout << endl;
    }

    return 0;
}
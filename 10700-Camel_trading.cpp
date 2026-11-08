#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int n;
    string line;

    cin >> n;

    while (n--){
        cin >> line;

        vector <long long> Nums;
        vector <char> Ops;
        vector <long long> TempMax;
        vector <long long> TempMin;

        stringstream ss(line);
        long long num;
        char op;

        ss >> num;
        TempMax.push_back(num);
        TempMin.push_back(num);

        while (ss >> op >> num){
            Ops.push_back(op);
            Nums.push_back(num);
        }

        // max pos
        long long max_val = 1;
        int j = 0;

        for (int i = 0; i < Ops.size(); ++i){
            if (Ops[i] == '+'){
                TempMax[j] += Nums[i];
            }else{
                j++;
                TempMax.push_back(Nums[i]);
            }
        }

        for (int i = 0; i < TempMax.size(); ++i){
            max_val *= TempMax[i];
        }

        // min sop
        long long min_val = 0;
        int k = 0;

        for (int i = 0; i < Ops.size(); ++i){
            if (Ops[i] == '*'){
                TempMin[k] *= Nums[i];
            }else{
                k++;
                TempMin.push_back(Nums[i]);
            }
        }

        for (int i = 0; i < TempMin.size(); ++i){
            min_val += TempMin[i];
        }

        cout << "The maximum and minimum are " << max_val << " and " << min_val << "." << endl;
    }

    return 0;
}
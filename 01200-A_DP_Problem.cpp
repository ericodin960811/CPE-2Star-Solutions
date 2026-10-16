#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main(){
    int t;
    string line, formula, term;
    
    cin >> t;
    cin.ignore();
    
    while (t--){
        getline(cin, line);
        
        int side = 1;
        formula = "";
        int totalX = 0;
        int totalConst = 0;
        int x;

        for (int i = 0; i < line.size(); ++i){
            if (line[i] == '+' || line[i] == '-' || line[i] == '='){
                if (line[i] == '+'){
                    formula += " +";
                }else if (line[i] == '-'){
                    formula += " -";
                }else{
                    formula += " = ";
                }
            }else{
                formula += line[i];
            }
        }
        
        stringstream ss(formula);
        while (ss >> term){
            if (term.back() == 'x'){
                if (term == "x" || term == "+x" || term == "-x"){
                    if (term == "-x"){
                        totalX += -1 * side;
                    }else{
                        totalX += 1 * side;
                    }
                }else{
                    term.pop_back();
                    totalX += stoi(term) * side;
                }
            }else if (term == "="){
                side = -1;
            }else{ // const
                totalConst += stoi(term) * side;
            }
        }
        
        if (totalX == 0){
            if (totalConst == 0){
                cout << "IDENTITY" << endl;
            }else{
                cout << "IMPOSSIBLE" << endl;
            }
        }else{
            x = floor(-(double)totalConst / totalX);
            cout << x << endl;
        }
    }
    
    return 0;
}
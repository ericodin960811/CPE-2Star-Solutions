#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int counter = 0;
    int n;
    
    while (cin >> n && n){
        vector <int> Ans;
        int num;
        
        counter++;
        cout << "Game " << counter << ':' << endl;
        
        for (int i=0; i<n; ++i){
            cin >> num;
            Ans.push_back(num);
        }
        
        while (true){                       // *
            vector <int> Guess;
            bool stop = false;
            bool AllStop = true;
            
            for (int i=0; i<n; ++i){
                cin >> num;
                if (num == 0){
                    stop = true;
                }else{
                    stop = false;
                }
                AllStop = (stop && AllStop);
                Guess.push_back(num);
            }
            
            if (AllStop){
                break;
            }
            
            int A = 0;
            int B = 0;
            int countAns[10] = {0};
            int countGuess[10] = {0};
            
            // A
            for (int i=0; i<n; ++i){
                if (Ans[i] == Guess[i]){
                    A++;
                }
            }
            
            // B
            for (int i=0; i<n; ++i){
                countAns[Ans[i]] += 1;
            }
            for (int i=0; i<n; ++i){
                countGuess[Guess[i]] += 1;
            }
            for (int i=1; i<=9; ++i){
                B += min(countAns[i], countGuess[i]);
            }
            B -= A;

            cout << "    (" << A << ',' << B << ')' << endl;
        }
    }
    
    
    return 0;
}
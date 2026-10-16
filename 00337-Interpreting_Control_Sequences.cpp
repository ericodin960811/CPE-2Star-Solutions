#include <iostream>
#include <cstring> // memset
#include <cctype>
#include <string>
using namespace std;

int main(){
    int counter = 0;
    int n;
    
    while (cin >> n && n){
        cin.ignore();
        
        string line = "";
        char screen[10][10];
        int row = 0; int col = 0;
        bool isInsert = false;
        
        memset(screen, ' ', sizeof(screen));
        
        while (n--){
            getline(cin, line);
            for (int i=0; i<line.size(); ++i){
                if (line[i] == '^'){
                    if (line[i+1] == 'b'){
                        col = 0;
                        i++;
                    }else if (line[i+1] == 'c'){
                        memset(screen, ' ', sizeof(screen));
                        i++;
                    }else if (line[i+1] == 'd'){
                        if (row + 1 < 10){
                            row++;
                        }
                        i++;
                    }else if (line[i+1] == 'e'){
                        for (int j=col; j<10; ++j){
                            screen[row][j] = ' ';
                        }
                        i++;
                    }else if (line[i+1] == 'h'){
                        row = 0; col = 0;
                        i++;
                    }else if (line[i+1] == 'i'){
                        isInsert = true;
                        i++;
                    }else if (line[i+1] == 'l'){
                        if (col -1 >= 0){
                            col--;
                        }
                        i++;
                    }else if (line[i+1] == 'o'){
                        isInsert = false;
                        i++;
                    }else if (line[i+1] == 'r'){
                        if (col + 1 < 10){
                            col++;
                        }
                        i++;
                    }else if (line[i+1] == 'u'){
                        if (row - 1 >= 0){
                            row--;
                        }
                        i++;
                    }else if (line[i+1] == '^'){
                        if (isInsert){
                            for (int j=9; j>col; j--){
                                screen[row][j] = screen[row][j-1];
                            }
                            screen[row][col] = '^';
                            if (col + 1 < 10){
                                col++;
                            }
                        }else{
                            screen[row][col] = '^';
                            if (col + 1 < 10){
                                col++;
                            }
                        }
                        i++;
                    }else if (isdigit(line[i+1])){
                        row = line[i+1] - '0';
                        col = line[i+2] - '0';
                        i += 2;
                    }
                }else{
                    if (isInsert){
                        for (int j=9; j>col; j--){
                            screen[row][j] = screen[row][j-1];
                        }
                        screen[row][col] = line[i];
                        if (col + 1 < 10){
                            col++;
                        }
                    }else{
                        screen[row][col] = line[i];
                        if (col + 1 < 10){
                            col++;
                        }
                    }
                }
            }
        }
        
        counter++;
        cout << "Case " << counter << endl;
        cout << "+----------+" << endl;
        
        for (int i=0; i<10; ++i){
            cout << '|';
            for (int j=0; j<10; ++j){
                cout << screen[i][j];
            }
            cout << '|' << endl;
        }

        cout << "+----------+" << endl;
    }
    
    return 0;
}
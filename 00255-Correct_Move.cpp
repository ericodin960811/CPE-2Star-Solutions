#include <iostream>
using namespace std;

int main(){
    int king, queen, queen_new;

    while (cin >> king >> queen >> queen_new){
        if (king == queen){
            cout << "Illegal state" << endl;
            continue;
        }

        int kr = king / 8, kc = king % 8;
        int qr = queen / 8, qc = queen % 8;
        int qnr = queen_new / 8, qnc = queen_new % 8;
        
        bool IM = false;
        // not move, not move diagonally, not jump over the king
        if (queen == queen_new){
            IM = true;
        }else{
            if (qr != qnr && qc != qnc){
                IM = true;
            }else{
                if ((qnr == kr && qr == kr) && ((queen <= king && king <= queen_new) || (queen_new <= king && king <= queen))){
                    IM = true;
                }else if ((qnc == kc && qc == kc) && ((queen <= king && king <= queen_new) || (queen_new <= king && king <= queen))){
                    IM = true;
                }
            }
        }
        if (IM){
            cout << "Illegal move" << endl;
            continue;
        }

        bool MNA = false;

        if (qnr == kr){
            if (king + 1 == queen_new || king - 1 == queen_new){
                MNA = true;
            }
        }else if (qnc == kc){
            if (king + 8 == queen_new || king - 8 == queen_new){
                MNA = true;
            }
        }
        if (MNA){
            cout << "Move not allowed" << endl;
            continue;
        }

        if ((king == 0 && queen_new == 9) || (king == 7 && queen_new == 14) || (king == 56 && queen_new == 49) || (king == 63 && queen_new == 54)){
            cout << "Stop" << endl;
        }else{
            cout << "Continue" << endl;
        }
    }

    return 0;
}
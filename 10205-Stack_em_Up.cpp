#include <iostream>
#include <sstream>
using namespace std;

struct Card{
    string value;
    string suit;
};

void initDeck(Card deck[]){
    string suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string values[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    int index = 0;

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 13; ++j){
            deck[index].suit = suits[i];
            deck[index].value = values[j];
            index++;
        }
    }
}

int main(){
    int t, n, k;
    bool first = true;

    cin >> t;

    while (t--){
        Card deck[52];
        int order[105][55];
        string line;

        initDeck(deck);
        cin >> n;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < 52; ++j){
                cin >> order[i][j];
            }
        }
        cin.ignore();

        while (getline(cin, line)){
            if (line.empty()) break;

            stringstream ss(line);
            ss >> k;

            Card temp[52];
            
            for (int i = 0; i < 52; ++i){
                temp[i] = deck[order[k - 1][i] - 1];
            }

            for (int i = 0; i < 52; ++i){
                deck[i] = temp[i];
            }
        }

        if (!first){
            cout << endl;
        }

        first = false;

        for (int i = 0; i < 52; ++i){
            cout << deck[i].value << " of " << deck[i].suit << endl;
        }
        
    }
}
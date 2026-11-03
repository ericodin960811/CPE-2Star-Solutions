#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    int t, n;
    string line;
    bool first = true;

    cin >> t;
    while (t--){
        string candidates[21];
        vector <vector<int>> Votes;
        bool eliminated[21] = {false};

        cin >> n;
        cin.ignore();

        for (int i = 1; i <= n; ++i){
            getline(cin, candidates[i]);
        }

        while (getline(cin, line)){
            if (line.empty()) break;

            stringstream ss(line);
            int vote;
            vector <int> preference;

            while (ss >> vote){
                preference.push_back(vote);
            }

            if (!preference.empty()){
                Votes.push_back(preference);
            }
        }

        while (true){
            int candidates_vote[21] = {0};
            int max_vote = 0;
            int min_vote = 1e9;

            for (int i = 0; i < Votes.size(); ++i){
                for (int j = 0; j < Votes[i].size(); ++j){
                    if (!eliminated[Votes[i][j]]){
                        candidates_vote[Votes[i][j]]++;
                        break;
                    }
                }
            }

            for (int i = 1; i <= n; ++i){
                if (!eliminated[i]){
                    max_vote = max(max_vote, candidates_vote[i]);
                    min_vote = min(min_vote, candidates_vote[i]);
                }
            }

            // 50 %
            int half = Votes.size() / 2;
            bool hasHalf = false;
            vector <string> Winners;

            for (int i = 1; i <= n; ++i){
                if (!eliminated[i] && candidates_vote[i] > half){
                    Winners.push_back(candidates[i]);
                    hasHalf = true;
                }
            }
            if (hasHalf){
                if (!first) cout << endl;
                first = false;

                for (string w : Winners){
                    cout << w << endl;
                }
                break;
            }

            // all ties
            if (max_vote == min_vote){
                if (!first) cout << endl;
                first = false;

                for (int i = 1; i <= n; ++i){
                    if (!eliminated[i]){
                        cout << candidates[i] << endl;
                    }
                }
                break;
            }

            // eliminate
            for (int i = 1; i <= n; ++i){
                if (!eliminated[i] && candidates_vote[i] == min_vote){
                    eliminated[i] = true;
                }
            }
        }
    }

    return 0;
}
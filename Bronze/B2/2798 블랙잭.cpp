#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tc, goal, ent = 0;
    vector<int> card;
    cin >> tc >> goal;
    for (int i = 0; i < tc; i++) {
        int a;
        cin >> a;
        card.push_back(a);
    }
    for(int i = 0; i < tc-2; i++){
        for(int ii = i + 1; ii < tc - 1; ii++){
            for(int iii = ii + 1; iii < tc; iii++){
                if((goal-ent) > (goal - (card[i] + card[ii] + card[iii])) && goal >= (card[i] + card[ii] + card[iii])){
                    ent = card[i] + card[ii] + card[iii];
                }
            }
        }
    }
    cout << ent;
}
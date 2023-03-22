#include <bits/stdc++.h>
#define INF __LONG_LONG_MAX__
#define ll long long
using namespace std;
int main(){
    int N; cin >> N;
    deque<ll> dice;
    for(int i = 0; i < 6; i++){
        int a; cin >> a;
        dice.push_back(a);
    }
    if(N == 1){
        int maxe = *max_element(dice.begin(), dice.end());
        int tempres = 0;
        for(int i = 0; i < 6; i++){
            if(dice[i] == maxe) continue;
            tempres += dice[i];
        } 
        cout << tempres;
        return 0;
    }
    int mini = 51, minj = 101, mink = 151;
    for(int i = 0; i < 6; i++){
        int temp1 = dice[i];
        mini = min(mini, temp1);
        for(int j = 0; j < 6; j++){
            if(i + j == 5 || i == j) continue;
            int temp2 = dice[i]+dice[j];
            minj = min(minj, temp2);
            for(int k = 0; k < 6; k++){
                if(i + k == 5 || j + k == 5 || i == k || j == k) continue;
                int temp3 = dice[i] + dice[j] + dice[k];
                mink = min(mink, temp3);
            }
        }
    }
    
    ll A = mini, B = minj - mini, C = mink - minj;
    ll side = 4*(A*N*(N-1)+B*N);
    ll tp = 4*C + 4*(N-2)*B + A*pow((N-2), 2);
    ll result = side + tp;
    cout << result;
}
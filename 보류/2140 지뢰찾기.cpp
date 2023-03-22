#include <bits/stdc++.h>
using namespace std;
char board[101][101]; 
int moveset[2][8] = {{1, 1, 0, -1, -1, -1, 0, 1}, {0, 1, 1, 1, 0, -1, -1, -1}};
int maxn;
queue<pair<int, int>> q0, q1, q2, q3, qt;
void ans0(){
    while(!q0.empty()){
        int cx = q0.front().first;
        int cy = q0.front().second;
        q0.pop();
        for(int i = 0; i < 8; i++){
            int dx = cx + moveset[0][i];
            int dy = cy + moveset[1][i];
            if(board[dy][dx] == '#') 
                board[dy][dx] = 'F';
        }
    }
}
void ans1(){
    while(!q1.empty()){
        int cx = q1.front().first;
        int cy = q1.front().second;
        q1.pop();
        pair<int, int> loc;
        int sharp = 0;
        for(int i = 0; i < 8; i++){
            int dx = cx + moveset[0][i];
            int dy = cy + moveset[1][i];
            if(board[dy][dx] == '#' || board[dy][dx] == 'T') {
                sharp++;
                loc = {dx, dy};
            }
        }
        if(sharp == 1){
            board[loc.second][loc.first] = 'T';
        }
    }
}
void ans2(){
    while(!q2.empty()){
        int cx = q2.front().first;
        int cy = q2.front().second;
        q2.pop();
        pair<int, int> loc[2];
        int sharp = 0;
        for(int i = 0; i < 8; i++){
            int dx = cx + moveset[0][i];
            int dy = cy + moveset[1][i];
            if(board[dy][dx] == '#' || board[dy][dx] == 'T') {
                loc[sharp] = {dx, dy};
                sharp++;
            }
        }
        if(sharp == 2){
            board[loc[0].second][loc[0].first] = 'T';
            board[loc[1].second][loc[1].first] = 'T';
        }
    }
}
void ans3(){
    while(!q3.empty()){
        int cx = q3.front().first;
        int cy = q3.front().second;
        q3.pop();
        for(int i = 0; i < 8; i++){
            int dx = cx + moveset[0][i];
            int dy = cy + moveset[1][i];
            if(board[dy][dx] == '#'){
                board[dy][dx] = 'T';
                qt.push({dx, dy});
            }
        }
    }
}
int main(){
    cin >> maxn;
    if(maxn < 3){
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= maxn; i++){
        for(int j = 1; j <= maxn; j++){
            char c; cin >> c;
            if(c == '0') q0.push({j, i});
            else if(c == '1') q1.push({j, i});
            else if(c == '2') q2. push({j, i});
            else if(c == '3') q3.push({j, i});
            board[i][j] = c;
        }
    }
    ans0();
    ans3();
    ans1();
    ans2();
    int ansnum = 0;
    for(int i = 2; i <= maxn - 1; i++){
        for(int j = 2; j <= maxn - 1; j++){
            if(board[i][j] == '#' || board[i][j] == 'T'){
                ansnum++;
            }
        }
    }
    cout << ansnum;
}
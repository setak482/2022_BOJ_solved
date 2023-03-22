#include<bits/stdc++.h>
#define INF 987412365
using namespace std;
char B_board[8][8] = {
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'}
};
char W_board[8][8] = {
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'},
    {'W','B','W','B','W','B','W','B'},
    {'B','W','B','W','B','W','B','W'}
};
char V_board[50][50];
int mx, my;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> my >> mx;
    for(int i = 0; i < my; i++){
        for(int j = 0; j < mx; j++){
            cin >> V_board[i][j];
        }
    }
    int bmin, wmin, emin = INF;
    for(int i = 0; i < my-7; i++){
        for(int j = 0; j < mx-7; j++){
            bmin = 0; wmin = 0;
            for(int y = i; y < i+8; y++){
                for(int x = j; x < j+8; x++){
                    if(V_board[y][x] != B_board[y-i][x-j]) bmin++;
                    else if(V_board[y][x] != W_board[y-i][x-j]) wmin++;
                }
            }
            emin = min(emin, min(wmin, bmin));
        }
    }
    cout << emin;
}
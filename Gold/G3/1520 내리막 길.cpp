#include <bits/stdc++.h>
using namespace std;
int maxy, maxx, cnt;
int arr[501][501];
int dp[501][501];
int moveset[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}}; // x, y / R D L U
int dfs(int x, int y){
    if(x == maxx && y == maxy) return 1;
    if(dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + moveset[0][i];
        int ny = y + moveset[1][i];
        if(nx >= 1 && ny >= 1 && nx <= maxx && ny <= maxy){
            if(arr[y][x] > arr[ny][nx]){
                dp[y][x] += dfs(nx, ny);
            }
        }
    }
    return dp[y][x];
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> maxy >> maxx;
    for(int i = 1; i <= maxy; i++){
        for(int j = 1; j <= maxx; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(1, 1);
}
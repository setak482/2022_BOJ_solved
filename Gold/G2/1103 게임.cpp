#include <bits/stdc++.h>
using namespace std;
int maxy, maxx, cnt;
int arr[51][51];
int dp[51][51];
bool visited[51][51];
int moveset[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}}; // x, y / R D L U
int dfs(int x, int y){
    if(x < 1 || y < 1 || x > maxx || y > maxy || arr[y][x] == 0) return 0;
    if(visited[y][x]){
        cout << -1 << '\n';
        exit(0);
    }
    if(dp[y][x] != -1) return dp[y][x];
    visited[y][x] = true;
    dp[y][x] = 0;
    int cofin = arr[y][x];
    for(int i = 0; i < 4; i++){
        int nx = x + (moveset[0][i] * cofin);
        int ny = y + (moveset[1][i] * cofin);
        dp[y][x] = max(dp[y][x], dfs(nx, ny) + 1);
    }
    visited[y][x] = false;
    return dp[y][x];
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> maxy >> maxx;
    for(int i = 1; i <= maxy; i++){
        for(int j = 1; j <= maxx; j++){
            char c; cin >> c;
            if(c != 'H') arr[i][j] = c - '0';
            else arr[i][j] = 0;
        }
    }
    cout << dfs(1, 1);
}
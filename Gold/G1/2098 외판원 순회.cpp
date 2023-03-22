#include <bits/stdc++.h>
#define INF 987412365
using namespace std;
int siz;
int graph[16][16];
int dp[16][1 << 16];
int dfs(int cur, int visited){
    if(dp[cur][visited] != 0){
        return dp[cur][visited];
    }
    if(visited == (1 << siz)-1){
        if(graph[cur][0] != 0){
            return graph[cur][0];
        }
        else{
            return INF;
        }
    }
    int res = INF;
    for(int i = 0; i < siz; i++){
        if(!(visited & (1 << i)) && (graph[cur][i] != 0)){
            res = min(res, graph[cur][i] + dfs(i, visited + (1 << i)));
        }
    }
    dp[cur][visited] = res;
    return res;
}
int main(){
    cin >> siz;
    for(int i = 0; i < siz; i ++){
        for(int j = 0; j < siz; j++){
            cin >> graph[i][j];
        }
    }
    cout << dfs(0, 1);
}
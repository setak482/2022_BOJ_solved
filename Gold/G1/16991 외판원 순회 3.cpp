#include <bits/stdc++.h>
#define point pair<int, int>
#define INF 987412365
using namespace std;
int siz;
double graph[16][16];
double dp[16][1 << 16];
double dist(point a, point b){
    return abs(sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second)));
}
double dfs(int cur, int visited){
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
    double res = INF;
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
    vector<point> vp;
    for(int i = 0; i < siz; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    for(int i = 0; i < siz-1; i++){
        for(int j = i+1; j < siz; j++){
            graph[i][j] = dist(vp[i], vp[j]);
            graph[j][i] = dist(vp[j], vp[i]);
        }
    }
    cout.fixed;
    cout.precision(17);
    cout << dfs(0, 1);
}
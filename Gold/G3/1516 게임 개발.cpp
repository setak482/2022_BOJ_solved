#include <bits/stdc++.h>
using namespace std;
vector<int> graph[501];
int linked[501];
int tms[501], dp[501];
int vertex, edge;
int main(){
    cin >> vertex;
    queue<int> q;
    for(int i = 1; i <= vertex; i++){
        cin >> tms[i];
        dp[i] = tms[i];
        while(1){
            int b; cin >> b;
            if(b == -1) break;
            graph[b].push_back(i);
            linked[i]++;
        }
    }
    for(int i = 1; i <= vertex; i++){
        if(linked[i] == 0){
            q.push(i);
        }
    }
    for(int i = 1; i <= vertex; i++){
        int temp = q.front();
        q.pop();
        for(auto& v : graph[temp]){
            linked[v]--;
            dp[v] = max(dp[v],dp[temp]+tms[v]);
            if(linked[v] == 0){
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= vertex; i++){
        cout << dp[i] << '\n';
    }
}
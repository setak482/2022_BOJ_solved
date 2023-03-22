#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
bool visited[1001];
int vertex, edge, result = 0;

void dfs(int start){
    visited[start] = true;
    for(auto& i : graph[start]){
        if(!visited[i]) dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> vertex >> edge;
    for(int i = 1; i < edge+1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    for(int i = 1; i < vertex+1; i++){
        if(visited[i] != true){
            dfs(i);
            result++;
        }
    }
    cout << result;
}
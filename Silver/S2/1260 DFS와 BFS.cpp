#include <bits/stdc++.h>
#define SIZE 1001
using namespace std;
vector<int> graph[SIZE];
int vertex, edge;
bool dfs_visited[SIZE], bfs_visited[SIZE];
void dfs(int start){
    dfs_visited[start] = true;
    cout << start << ' ';
    for(int i = 0; i < graph[start].size(); i++){
        if(!dfs_visited[graph[start][i]]) dfs(graph[start][i]);
    }
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    bfs_visited[start] = true;      // 방문표시
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i = 0; i < graph[cur].size(); i++){
            if(!bfs_visited[graph[cur][i]]){
                q.push(graph[cur][i]);
                bfs_visited[graph[cur][i]] = true;
            }
        }
    }
}
int main(){
    int init;
    cin >> vertex >> edge >> init;
    for(int i = 0; i < edge; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= vertex; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(init);
    cout << '\n';
    bfs(init);
}
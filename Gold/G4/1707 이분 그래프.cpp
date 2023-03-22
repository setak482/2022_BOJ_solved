#include <bits/stdc++.h>
using namespace std;
vector<int> graph[20001];
int visited[20001];
int vertex, edge;
void bfs(int init){
    queue<int> q;
    q.push(init);
    visited[init] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto& i : graph[cur]){
            if(!visited[i]){
                visited[i] = visited[cur] * -1;
                q.push(i);
            }
        }
    }
}
bool bipartite(){
    for(int i = 1; i <= vertex; i++){
        for(auto& j : graph[i]){
            if(visited[j] == visited[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        cin >> vertex >> edge;
        for(int i = 0; i < edge; i++){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);   // 무방향 그래프 일때
        }
        for(int i = 1; i <= vertex; i++){
            if(!visited[i])
                bfs(i);
        }
        if(bipartite()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        for (int i = 0; i <= vertex; i++) {
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
    }
}
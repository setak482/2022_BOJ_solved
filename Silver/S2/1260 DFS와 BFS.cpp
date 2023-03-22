//DFS와 BFS bj1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int node, edge, head;
bool dfs_visited[1001];
bool bfs_visited[1001];
vector<vector<int>> adj(1001);

void dfs(vector<vector<int>> v, int head) {
    dfs_visited[head] = true;
    sort(v[head].begin(), v[head].end());
    cout << head << " ";
    for (int i = 0; i < v[head].size(); i++){
        int next = v[head][i];
        if(!dfs_visited[next]) dfs(v, next);
    }
    if (head==node) return; 
}
void bfs(vector<vector<int>> v, int head) {
    for (int i = 1; i < node+1; i++){
        sort(v[i].begin(), v[i].end());
    }
    queue<int> q;
    q.push(head);
    bfs_visited[head] = true;
    while(!q.empty()){
        int elem = q.front();
        q.pop();
        cout << elem << " ";
        
        for (int i = 0; i < v[elem].size(); i++){
            int next = v[elem][i];
            if(!bfs_visited[next]){
                q.push(next);
                bfs_visited[next] = true;
            }
        }
    }
}
int main() {
    cin >> node >> edge >> head;

    for (int i = 0; i < edge; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(adj, head);
    cout << "\n";
    bfs(adj, head);
}
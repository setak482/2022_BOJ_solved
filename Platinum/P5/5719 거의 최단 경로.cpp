#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
int edge, vertex, s, e, dij[501];
bool visited[501];
vector<pair<int, int>> graph[501];
vector<pair<int, int>> archive[501];
void dijkstra(){
    for (int i = 0; i <= vertex; i++) dij[i] = INF;
    priority_queue<pair<int, int>> pq;
    dij[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dij[cur] < cost) continue;
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int next_cost = cost + graph[cur][i].second;
            if(graph[cur][i].second == -1) continue;
            if(dij[next] > next_cost){
                dij[next] = next_cost;
                pq.push({-dij[next], next});
                archive[next].clear();
                archive[next].push_back({cur, next_cost});
            }
            else if (dij[next] == next_cost) 
                archive[next].push_back({cur, next_cost});
        }
    }
}
void removes(int end){
    queue<int> q;
    q.push(end);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(int i = 0; i < archive[cur].size(); i++){
            int next = archive[cur][i].first;
            for(int j = 0; j < graph[next].size(); j++){
                if(graph[next][j].first == cur)
                    graph[next][j].second = -1;
            }
            q.push(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(true){
        memset(graph, 0, sizeof(graph));
        memset(archive, 0, sizeof(archive));
        memset(visited, 0, sizeof(visited));
        cin >> vertex >> edge;
        if(vertex == 0 && edge == 0) exit(0);
        cin >> s >> e;
        for(int i = 0; i < edge; i++){
            int a, b, c; cin >> a >> b >> c;
            graph[a].push_back({b, c});
        }
        dijkstra();
        removes(e);
        dijkstra();
        if(dij[e] == INF) cout << "-1\n";
        else cout << dij[e] << '\n';
    }
}
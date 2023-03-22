#include <bits/stdc++.h>
#define INF 987412365
using namespace std;
int vertex, init;
int dij[10001];
vector<pair<int, int>> graph[10001];
void dijkstra(){
    for (int i = 1; i <= vertex; i++) dij[i] = INF;
    priority_queue<pair<int, int>> pq;
    dij[init] = 0;
    pq.push({0, init});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;
            if(dij[next] > cost + next_cost){
                dij[next] = cost + next_cost;
                pq.push({dij[next], next});
            }
        }
    }
}
int main(){
    cin >> vertex;
    if(vertex == 1){
        cout << 0;
        exit(0);
    }
    for(int i = 0; i < vertex-1; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int max_diff = 0;
    int node_A;
    init = 1;
    dijkstra();
    for(int i = 1; i <= vertex; i++){
        if(max_diff < dij[i]){
            node_A = i;
            max_diff = dij[i];
        }
    }
    init = node_A;
    dijkstra();
    max_diff = 0;
    for(int i = 1; i <= vertex; i++)
        max_diff = max(max_diff, dij[i]);
    cout << max_diff;
}
#include <bits/stdc++.h>
#define endl '\n'
#define INF 999999999
using namespace std;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};
int edge, vertex, init;
int dij[801];
vector<pair<int, int>> graph[801];
void dijkstra(){
    for (int i = 1; i <= edge; i++) dij[i] = INF;
    priority_queue<pair<int, int>> pq;
    dij[init] = 0;
    pq.push({0, init});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;
            if(dij[next] > cost + next_cost){
                dij[next] = cost + next_cost;
                pq.push({-dij[next], next});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> edge >> vertex;
    for(int i = 0; i < vertex; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    init = 1;
    dijkstra();
    int NUL_v1 = dij[v1];
    int NUL_v2 = dij[v2];
    init = v1;
    dijkstra();
    int v1_v2 = dij[v2];
    int v1_end = dij[edge];
    init = v2;
    dijkstra();
    int v2_end = dij[edge];
    int res = INF;
    res = min(res, NUL_v1 + v1_v2 + v2_end);
    res = min(res, NUL_v2 + v1_v2 + v1_end);
    if(v1_v2 == INF || res == INF) cout << -1;
    else cout << res;
}
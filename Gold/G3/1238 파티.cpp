#include <bits/stdc++.h>
#define endl '\n'
#define INF 999999999
using namespace std;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};
int edge, vertex, init, fin;
int dij[1001];
vector<pair<int, int>> graph[1001];
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
    cin >> fin;
    for(int i = 0; i < vertex; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int res = 0;
    for(int i = 1; i <= edge; i++){
        init = i;
        dijkstra();
        int temp = dij[fin];
        init = fin;
        dijkstra();
        res = max(res, temp + dij[i]);
    }
    cout << res;
}
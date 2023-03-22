#include <bits/stdc++.h>
#define endl '\n'
#define INF 999999999
using namespace std;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};
int edge, vertex;
int st, en;
int ITEM[1001];
int dij[1001];
vector<pair<int, int>> graph[1001];
void dijkstra(){
    priority_queue<pair<int, int>> pq;
    dij[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dij[cur] < cost) continue;
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
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cin >> st >> en;
    for (int i = 1; i <= vertex; i++) dij[i] = INF;
    dijkstra();
    cout << dij[en];
}
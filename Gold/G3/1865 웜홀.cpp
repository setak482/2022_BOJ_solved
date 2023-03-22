#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;
struct node{
    int to;
    int weight;
};
vector<node> graph[501];
int dist[501];
int vertex, edge, wormhole;
bool bellman_ford(){
    for(int i = 1; i <= vertex; i++){
        dist[i] = INF;
    }
    dist[1] = 0; // start
    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++){
            for(int k = 0; k < graph[j].size(); k++){
                int next = graph[j][k].to;
                int cost = graph[j][k].weight;
                if(dist[next] > dist[j] + cost){
                    dist[next] = dist[j] + cost;
                    if(i == vertex){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> vertex >> edge >> wormhole;
        for(int j = 1; j <= edge; j++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
        for(int j = 1; j <= wormhole; j++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({b, -c});
        }
        if(bellman_ford()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        for(int i = 1; i <= vertex; i++){
            graph[i].clear();
        }
    }
}
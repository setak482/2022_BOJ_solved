#include <bits/stdc++.h>
#define INF 987412365
using namespace std;
int move_set[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
int maps[126][126];
int dist[126][126];
int siz;
void init(){
    for(int i = 0; i < siz; i++){
        for(int j = 0; j < siz; j++){
            dist[i][j] = INF;
        }
    }
}
void dijkstra(){
    init();
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-maps[0][0], {0, 0}});
    dist[0][0] = maps[0][0];
    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + move_set[0][i];
            int dy = y + move_set[1][i];
            int new_cost = cost + maps[dy][dx];
            if(dx >= 0 && dy >= 0 && dx < siz && dy < siz){
                if(dist[dy][dx] > new_cost){
                    dist[dy][dx] = new_cost;
                    pq.push({-dist[dy][dx], {dx, dy}});
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cnt = 0;
    while(1){
        cin >> siz;
        if(siz == 0) break;
        for(int i = 0; i < siz; i++){
            for(int j = 0; j < siz; j++){
                cin >> maps[i][j];
            }
        }
        cnt++;
        dijkstra();
        cout << "Problem " << cnt << ": " << dist[siz-1][siz-1] << '\n';
        memset(maps, 0, sizeof(maps));
    }
    return 0;
}
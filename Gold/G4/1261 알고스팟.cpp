#include <bits/stdc++.h>
using namespace std;
struct node{int x, y, step;};
int maxx, maxy;
int graph[101][101];
bool visited[101][101];
int movestep[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
int bfs(){
    deque<node> q;
    q.push_front({1, 1, 0});
    visited[1][1] = true;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int step = q.front().step;
        q.pop_front();
        if(x == maxx && y == maxy){
            return step;
        }
        for(int i = 0; i < 4; i++){
            int dx = x + movestep[0][i];
            int dy = y + movestep[1][i];
            if(dx > 0 && dx <= maxx && dy > 0 && dy <= maxy && visited[dy][dx] == false){
                if(graph[dy][dx] == 1){
                    q.push_back({dx, dy, step+1});
                    visited[dy][dx] = true;
                }
                else if(graph[dy][dx] == 0){
                    q.push_front({dx, dy, step});
                    visited[dy][dx] = true;
                }
            }
        }
    }
}
int main(){
    cin >> maxx >> maxy;
    for(int i = 1; i <= maxy; i++){
        for(int j = 1; j <= maxx; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    cout << bfs();
}
#include <bits/stdc++.h>
using namespace std;
int mx, my;
int graph[1001][1001];
map<pair<int, int>, int> mp;
int setsize[501];
int walk;
int nums = 1;
int move_set[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        walk++;
        for(int i = 0; i < 4; i++){
            int dx = cx + move_set[0][i];
            int dy = cy + move_set[1][i];
            if(dx >= 1 && dy >= 1 && dx <= mx && dy <= my && !mp.count({j, i}) && graph[dy][dx] == 0){
                q.push({dx, dy});
                mp.insert({{dx, dy}, nums});
            }
        }
    }
}
int main(){
    cin >> my >> mx;
    for(int i = 1; i <= my; i++){
        for(int j = 1; j <= mx; j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    for(int i = 1; i <= my; i++){
        for(int j = 1; j <= mx; j++){
            if(graph[i][j] == 0 && !mp.count({j, i})){
                bfs(j, i);
                setsize[nums] = walk;
                walk = 0;
            }
        }
    }
    for(int i = 1; i <= my; i++){
        for(int j = 1; j <= mx; j++){
            cout << graph[i][j];
        }
        cout << '\n';
    }
    cout << '\n' << (double)(end - start);
}
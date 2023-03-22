#include <bits/stdc++.h>
using namespace std;
int visited[101][101];
int nmap[101][101];
queue<pair<pair<int, int>, int>> q;
int xmove[4] = {0, 1, 0, -1};
int ymove[4] = {-1, 0, 1, 0};
int max_x, max_y;
int result;

bool isPossible(int a, int b){
    if(a < 1 || a > max_x || b < 1 || b > max_y || visited[b][a] || nmap[b][a] == 0){
        return false;
    }
    return true;
}

void bfs(){
    while(!q.empty()){ 
        int x = q.front().first.first; // 1
        int y = q.front().first.second; // 1
        int cnt = q.front().second; // 0
        q.pop();
        if(x == max_x && y == max_y){
            result = cnt;
            return;
        }
        for(int i = 0; i < 4; i++){
            int new_x = x + xmove[i]; // 2
            int new_y = y + ymove[i]; // 1
            if(isPossible(new_x, new_y)){
                visited[new_y][new_x]++;
                q.push({{new_x, new_y}, cnt+1});
            }
        }
    }
}
int main(){
    cin >> max_y >> max_x;
    for(int y = 1; y < max_y+1; y++){
        for(int x = 1; x < max_x+1; x++){
            scanf("%1d", &nmap[y][x]);
        }
    }
    visited[1][1] = 1;
    q.push({{1,1}, 1});
    bfs();
    cout << result;
}
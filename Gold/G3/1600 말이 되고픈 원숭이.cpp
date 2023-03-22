#include <bits/stdc++.h>
using namespace std;
struct monkey{
    int x;
    int y;
    int bomb;
    int walk;
};
int maps[201][201];
bool visited[201][201][31];
int b, maxx, maxy;
int moveset[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}};  // x, y
int moveset_S[2][8] = {{2, 1, -1, -2, -2, -1, 1, 2}, {1, 2, 2, 1, -1, -2, -2, -1}}; // x, y
bool isPossible(monkey mon){
    if(mon.x < 1 || mon.y < 1 || mon.x > maxx || mon.y > maxy || visited[mon.y][mon.x][mon.bomb] || maps[mon.y][mon.x] == 1){
        return false;
    }
    return true;
}
int bfs(){
    queue<monkey> q;
    monkey init;
    init.x = 1;
    init.y = 1;
    init.bomb = b;
    init.walk = 0;
    visited[1][1][b] = true;
    q.push(init);
    while(!q.empty()){
        monkey cur = q.front();
        q.pop();
        if(cur.x == maxx && cur.y == maxy){
            return cur.walk;
        }
        if(cur.bomb != 0){
            for(int i = 0; i < 8; i++){
                monkey power_monkey;
                power_monkey.x = cur.x + moveset_S[0][i];
                power_monkey.y = cur.y + moveset_S[1][i];
                power_monkey.bomb = cur.bomb - 1;
                power_monkey.walk = cur.walk + 1;
                if(isPossible(power_monkey)){
                    visited[power_monkey.y][power_monkey.x][power_monkey.bomb] = true;
                    q.push(power_monkey);
                }
            }
        }
        for(int i = 0; i < 4; i++){
            monkey next_monkey;
            next_monkey.x = cur.x + moveset[0][i];
            next_monkey.y = cur.y + moveset[1][i];
            next_monkey.bomb = cur.bomb;
            next_monkey.walk = cur.walk + 1;
            if(isPossible(next_monkey)){
                visited[next_monkey.y][next_monkey.x][cur.bomb] = true;
                q.push(next_monkey);
            }
        }
    }
    return -1;
}
int main(){
    cin >> b >> maxx >> maxy;
    for(int i = 1; i <= maxy; i++){
        for(int j = 1; j <= maxx; j++){
            cin >> maps[i][j];
        }
    }
    cout << bfs();
}
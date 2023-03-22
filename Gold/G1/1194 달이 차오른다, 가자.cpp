#include <bits/stdc++.h>
using namespace std;
char minimap[51][51];
int visited[51][51][1 << 7];
int moveset[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}}; // x, y
struct player{
    int x;
    int y;
    int keys;
};
int max_x, max_y;
queue<player> q;
bool isPos(player th){
    char current = minimap[th.y][th.x];
    if(th.x < 1 || th.y < 1 || th.x > max_x || th.y > max_y || current == '#' || visited[th.y][th.x][th.keys] || (current >= 'A' && current <= 'F')){
        if(current >= 'A' && current <= 'F'){
            int temp_key = th.keys & (1 << int(current) -'A');
            if(temp_key != 0){
                return true;
            }
        }
        return false;
    }
    return true;
}
void bfs(){
    while(!q.empty()){
        player origin = q.front();
        q.pop();
        if(minimap[origin.y][origin.x] == '1'){
            cout << visited[origin.y][origin.x][origin.keys] - 1;
            return;
        }
        for(int i = 0; i < 4; i++){
            player newer = origin;
            newer.x = origin.x + moveset[0][i];
            newer.y = origin.y + moveset[1][i];
            if(isPos(newer)){
                if(minimap[newer.y][newer.x] >= 'a' && minimap[newer.y][newer.x] <= 'f'){
                    if(visited[newer.y][newer.x][newer.keys] == 0){
                        newer.keys = origin.keys | (1 << (int(minimap[newer.y][newer.x]) - 'a'));
                        visited[newer.y][newer.x][newer.keys] = visited[origin.y][origin.x][origin.keys] + 1;
                        visited[newer.y][newer.x][origin.keys] = visited[origin.y][origin.x][origin.keys] + 1;
                        q.push(newer);
                    }
                }
                else if(minimap[newer.y][newer.x] == '.' || minimap[newer.y][newer.x] == '1'){
                    if(visited[newer.y][newer.x][newer.keys] == 0){
                        visited[newer.y][newer.x][newer.keys] = visited[origin.y][origin.x][origin.keys] + 1;
                        q.push(newer);
                    }
                }
                else if(minimap[newer.y][newer.x] >= 'A' && minimap[newer.y][newer.x] <= 'F'){
                    if(visited[newer.y][newer.x][newer.keys] == 0){
                        visited[newer.y][newer.x][newer.keys] = visited[origin.y][origin.x][origin.keys] + 1;
                        q.push(newer);
                    }
                }
            }
        }
    }
    cout << -1;
    exit(0);
}
int main(){
    cin >> max_y >> max_x;
    for(int i = 1; i <= max_y; i++){
        for(int j = 1; j <= max_x; j++){
            char c; scanf(" %c" , &c);
            if(c != '0') minimap[i][j] = c;
            else{
                minimap[i][j] = '.';
                q.push({j, i, 0});
                visited[i][j][0] = true;
            }
        }
    }
    // cout << '\n';
    // for(int i = 1; i <= max_y; i++){
    //     for(int j = 1; j <= max_x; j++){
    //         cout << minimap[i][j];
    //     }
    //     cout << '\n';
    // }
    bfs();
}
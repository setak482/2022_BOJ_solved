#include <bits/stdc++.h>
using namespace std;
char alph_map[21][21];
bool visited[26];
int moveset[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}};
int ecnt;
int max_x, max_y;
void dfs(int x, int y, int cnt){
    if(visited[alph_map[y][x] - 'A']){
        ecnt = max(cnt, ecnt);
        return;
    }
    else{
        visited[alph_map[y][x] - 'A'] = true;
        for(int i = 0; i < 4; i++){
            int newx = x + moveset[0][i];
            int newy = y + moveset[1][i];
            int hash = int(alph_map[newy][newx] - 'A');
            if(newx >= 1 && newx <= max_x && newy >= 1 && newy <= max_y){
                dfs(newx, newy, cnt+1);
            }
        }
        visited[alph_map[y][x] - 'A'] = false;
    }
}
int main(){
    cin >> max_y >> max_x;
    for(int i = 1; i <= max_y; i++){
        for(int j = 1; j <= max_x; j++){
            cin >> alph_map[i][j];
        }
    }
    visited[alph_map[1][1] - 'A'];
    dfs(1, 1, 0);
    cout << ecnt;
}
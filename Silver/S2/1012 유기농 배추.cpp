#include <bits/stdc++.h>
using namespace std;
int maps[51][51] = {0, };
int visited[51][51] = {0, };
int moves[2][4] = { {1, 0, -1, 0}, {0, 1, 0, -1} };
int depth = 0;
int max_x, max_y, max_baechu;
void init(){
    memset(visited, 0, sizeof(visited));
    memset(maps, 0, sizeof(maps));
    depth = 0;
}

bool ispossible(int a, int b) {
    if (a < 0 || a >= max_x || b < 0 || b >= max_y
        || visited[b][a] || maps[b][a] == 0) {
        return false;
    }
    return true;
}

void dfs(int x, int y){
    for(int i = 0; i < 4; i++){
        int new_x = x + moves[0][i];
        int new_y = y + moves[1][i];
        if(ispossible(new_x, new_y)){
            visited[new_y][new_x]++;
            dfs(new_x, new_y);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        cin >> max_x >> max_y >> max_baechu;
        for(int i = 0; i < max_baechu; i++){
            int a, b; cin >> a >> b;
            maps[b][a] = 1;
        }
        for(int y = 0; y < max_y; y++){
            for(int x = 0; x < max_x; x++){
                if(maps[y][x] == 1 && visited[y][x] == 0){
                    visited[y][x] = 1;
                    depth++;
                    dfs(x, y);
                }
            }
        }
        cout << depth << '\n';
        init();
    }
}
#include <bits/stdc++.h>
using namespace std;
char minimap[104][104];
bool visited[104][104];
int moveset[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}}; // x, y
bool door[26] = {0, };
int entire_docs;
struct thief{
    int x;
    int y;
};
int max_x, max_y;
void init(){
    memset(visited, false, sizeof(visited));
    memset(door, false, sizeof(door));
    entire_docs = 0;
}
bool isPos(thief th){
    char current = minimap[th.y][th.x];
    if(current <= 'a' && current >= 'z'){
        if(door[int(current-'a')]){
            minimap[th.y][th.x] = '.';
            return true;
        }
    }
    if(th.x < 1 || th.y < 1 || th.x > max_x+2 || th.y > max_y+2 || current == '*' || visited[th.y][th.x] == true || (current >= 'A' && current <= 'Z')){
        if(door[int(current)-int('A')]){
            minimap[th.y][th.x] = '.';
            return true;
        }
        return false;
    }
    return true;
}
void bfs(string keys){
    queue<thief> q;
    if(keys != "0"){
        for(auto& i : keys){
            door[int(i)-int('a')] = true;
        }
    }
    q.push({1, 1});
    visited[1][1] = true;
    while(!q.empty()){
        thief origin = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            thief newer = origin;
            newer.x = origin.x + moveset[0][i];
            newer.y = origin.y + moveset[1][i];
            if(isPos(newer)){
                if(minimap[newer.y][newer.x] == '$'){
                    entire_docs++;
                    visited[newer.y][newer.x] = true;
                    minimap[newer.y][newer.x] = '.';
                    q.push(newer);
                }
                else if(minimap[newer.y][newer.x] >= 'a' && minimap[newer.y][newer.x] <= 'z'){
                    door[int(minimap[newer.y][newer.x] - 'a')] = true;
                    memset(visited, false, sizeof(visited));
                    while(!q.empty()) q.pop();
                    visited[newer.y][newer.x] = true;
                    minimap[newer.y][newer.x] = '.';
                    q.push(newer);
                }
                else if(minimap[newer.y][newer.x] == '.'){
                    visited[newer.y][newer.x] = true;
                    q.push(newer);
                }
            }
        }
    }
}
int main(){
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++){
        cin >> max_y >> max_x;
        for(int i = 2; i <= max_y+1; i++){
            for(int j = 2; j <= max_x+1; j++){
                scanf(" %c", &minimap[i][j]);
            }
        }
        string temp;
        cin >> temp;
        for(int i = 1; i <= max_x+2; i++){
            minimap[1][i] = '.';
            minimap[max_y+2][i] = '.';
        }
        for(int i = 1; i <= max_y+2; i++){
            minimap[i][1] = '.';
            minimap[i][max_x+2] = '.';
        }
        bfs(temp);
        // for(int i = 1; i <= max_y+2; i++){
        //     for(int j = 1; j <= max_x+2; j++){
        //         cout << minimap[i][j];
        //     }
        //     cout << '\n';
        // }
        cout << entire_docs << '\n';
        init();
    }
}
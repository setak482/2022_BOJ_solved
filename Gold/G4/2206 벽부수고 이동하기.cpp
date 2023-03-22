#include <bits/stdc++.h>
using namespace std;
struct bfs_node{
    int x;
    int y;
    int depth;
    int destroy;
};
queue<bfs_node> q;
bool bfs_visited[1001][1001][2];
int nmap[1001][1001];
int moves[2][4] = {{1, 0, -1, 0}, {0, 1, 0, -1}}; //[0] = x [1] = y
int max_x, max_y, result;
bool isPossible(bfs_node node){
    if(node.x < 1 || node.x > max_x || node.y < 1 || node.y > max_y){
        return false;
    }
    return true;
}
int bfs(){
    bfs_visited[1][1][0] = true;
    bfs_node node;
    node.x = 1; node.y = 1;
    node.depth = 1; node.destroy = 0;
    q.push(node);
    while(!q.empty()){
        bfs_node node = q.front();
        q.pop();
        if(node.x == max_x && node.y == max_y){
            return node.depth;
        }
        for(int i = 0; i < 4; i++){
            bfs_node new_node;
            new_node.x = node.x + moves[0][i];
            new_node.y = node.y + moves[1][i];
            new_node.depth = node.depth + 1;
            new_node.destroy = node.destroy;
            if(!isPossible(new_node)) continue;
            if(bfs_visited[new_node.y][new_node.x][new_node.destroy]) continue;
            if(nmap[new_node.y][new_node.x] == 0){
                bfs_visited[new_node.y][new_node.x][new_node.destroy] = true;
                q.push(new_node);
            }
            if(nmap[new_node.y][new_node.x] == 1 && new_node.destroy == 0){
                bfs_visited[new_node.y][new_node.x][1] = true;
                new_node.destroy = 1;
                q.push(new_node);
            }
        }
    }
    return -1;
}
int main(){
    cin >> max_y >> max_x;
    for(int y = 1; y <= max_y; y++){
        for(int x = 1; x <= max_x; x++){
            scanf("%1d", &nmap[y][x]);
        }
    }
    cout << bfs();
}
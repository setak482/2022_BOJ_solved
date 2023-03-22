// 토마토
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int visited[1001][1001] = {0, };
int map[1001][1001];
queue<pair<pair<int, int>, int> > q;
vector<int> x_arrive = {0, 1, 0, -1};
vector<int> y_arrive = {1, 0, -1, 0};
int xmax, ymax;
int result;
int cnt = 0;
bool isPossible(int a, int b){
    if(a < 0 || a >= ymax || b < 0 || b >= xmax || visited[a][b] || map[a][b] == -1 || map[a][b] == 1){
        return false;
    }
    return true;
}

void bfs(){
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        result = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int new_x = x_arrive[i] + x;
            int new_y = y_arrive[i] + y;
            if(isPossible(new_y, new_x)){
                cnt--;
                q.push({{new_y, new_x}, result + 1});
                visited[new_y][new_x] = true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> xmax >> ymax;
    for(int i = 0; i < ymax; i++){
        for(int v = 0; v < xmax; v++){
            int c; cin >> c;
            if(c == 1){
                q.push({{i,v},0});
            }
            else if(c == 0){
                cnt++;
            }
            map[i][v] = c;
        }
    }
    bfs();
    if(cnt < 1){
        cout << result;
    }
    else{
        cout << -1;
    }
    return 0;
}
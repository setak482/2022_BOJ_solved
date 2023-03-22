#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
int bfs_checked[301][301] = {0, };
queue<pair< pair<int, int>, int> > q;
pair<int, int> goal;
vector<int> x_arrive {2, 1, -1, -2, -2, -1, 1, 2};
vector<int> y_arrive {1, 2, 2, 1, -1, -2, -2, -1};
queue<int> result;
int mem_size;

bool isPossible(pair<int, int> a){
    if(a.first < 0 || a.second < 0 || bfs_checked[a.first][a.second]){
        return false;
    }
    return true;
}

void init(){
    memset(bfs_checked,0,sizeof(bfs_checked));
}
void bfs(){
    while(!q.empty()){
        int x = q.front().first.second;
        int y = q.front().first.first;
        int depth = q.front().second;
        q.pop();
        if(make_pair(y, x) == goal){
            result.push(depth);
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        for(int i = 0; i < 8; i++){
            int cx = x_arrive[i] + x;
            int cy = y_arrive[i] + y;

            if(cx >= 0 && cx < mem_size && cy >= 0 && cy < mem_size && !bfs_checked[cy][cx]){
                q.push({{cy, cx}, depth+1});
                bfs_checked[cy][cx]++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> mem_size;
        int init_a, init_b; cin >> init_a >> init_b;
        int res_a, res_b; cin >> res_a >> res_b;
        goal = {res_a, res_b};
        q.push({{init_a, init_b}, 0});
        bfs();
        init();
    }
    while(!result.empty()){
        cout << result.front() << '\n';
        result.pop();
    }
}
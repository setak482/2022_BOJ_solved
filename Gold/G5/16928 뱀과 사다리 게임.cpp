#include <bits/stdc++.h>
using namespace std;
int warp[101];
bool visited[101] = {false, };
int bfs(){
    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({1, 0});
    while(!q.empty()){
        int cur = q.front().first;
        int turn = q.front().second;
        q.pop();
        if(cur == 100) return turn;
        if(cur > 100) continue;
        for(int i = 1; i <= 6; i++){
            int next = cur + i;
            if(next > 100) continue;
            if(warp[next]) next = warp[next];
            if(!visited[next]){
                visited[next] = true;
                q.push({next, turn+1});
            }
        }
    }
}
int main(){
    int a, b; cin >> a >> b;
    for(int i = 0; i < a + b; i++){
        int p, q; cin >> p >> q;
        warp[p] = q;
    }
    cout << bfs();
}
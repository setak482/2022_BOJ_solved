#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
bool prime[10001] = {false, };
void eratosthenes(){
    prime[1] = true;
    for(int i = 2; i <= 100; i++){
        if(prime[i]) continue;
        for(int j = i+i; j <= 10000; j += i){
            prime[j] = true;
        }
    }
}
bool visited[10001];
int st, ed;
int bfs(){
    queue<pp> q;
    q.push({st, 0});
    visited[st] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int dep = q.front().second;
        q.pop();
        if(cur == ed) return dep;
        int next;
        int mill = cur % 1000;
        int cent = (cur % 100) + floor(cur / 1000) * 1000;
        int dec = (cur % 10) + floor(cur / 100) * 100;
        int ann = floor(cur / 10) * 10;
        for(int i = 1; i <= 9; i++){
            next = (i*1000) + mill;
            if(!prime[next] && !visited[next]){
                visited[next] = true;
                q.push({next, dep+1});
            }
        }
        for(int i = 0; i <= 9; i++){
            next = (i*100) + cent;
            if(!prime[next] && !visited[next]){
                visited[next] = true;
                q.push({next, dep+1});
            }
        }
        for(int i = 0; i <= 9; i++){
            next = (i*10) + dec;
            if(!prime[next] && !visited[next]){
                visited[next] = true;
                q.push({next, dep+1});
            }
        }
        for(int i = 0; i <= 9; i++){
            next = i + ann;
            if(!prime[next] && !visited[next]){
                visited[next] = true;
                q.push({next, dep+1});
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    eratosthenes();
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> st >> ed;
        int res = bfs();
        if(res != -1) cout << res << '\n';
        else cout << "Impossible" << '\n';
        memset(visited, false, sizeof(visited));
    }
}
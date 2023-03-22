#include <bits/stdc++.h>
using namespace std;
bool bfs_visited[10001];
int fir_input, fin_result;
string bfs(){
    queue<pair<int, string>> q;
    q.push({fir_input, ""});
    bfs_visited[fir_input] = true;
    while(!q.empty()){
        int n = q.front().first;
        string cmd = q.front().second;
        q.pop();
        if(n == fin_result){
            return cmd;
        }
        int newn = (n * 2) % 10000;
        if(!bfs_visited[newn]){
            bfs_visited[newn] = true;
            if(newn == fin_result){
                return cmd + 'D';
            }
            q.push({newn, cmd + 'D'});
        }
        newn = n - 1;
        if(n == 0) newn = 9999;
        if(!bfs_visited[newn]){
            bfs_visited[newn] = true;
            if(newn == fin_result){
                return cmd + 'S';
            }
            q.push({newn, cmd + 'S'});
        }
        newn = (n % 1000) * 10 + (n / 1000);
        if(!bfs_visited[newn]){
            bfs_visited[newn] = true;
            if(newn == fin_result){
                return cmd + 'L';
            }
            q.push({newn, cmd + 'L'});
        }
        newn = (n % 10) * 1000 + (n / 10);
        if(!bfs_visited[newn]){
            bfs_visited[newn] = true;
            if(newn == fin_result){
                return cmd + 'R';
            }
            q.push({newn, cmd + 'R'});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        cin >> fir_input >> fin_result;
        cout << bfs() << '\n';
        memset(bfs_visited, 0, sizeof(bfs_visited));
    }
}
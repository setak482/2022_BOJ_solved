#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> q;
bool bfs_visited[100001];
int a, b, result;
int mini = 0, cnt = 0;
bool isPossible(int n){
    if (n < 0 || n > 100000 || bfs_visited[n])
		return false;
	return true;
}
void bfs(int head) {
    while(!q.empty()){
        int data = q.front().first;
        int depth = q.front().second;
        q.pop();
        bfs_visited[data] = true;
        if(mini && mini == depth && data == b){
            cnt++;
        }
        if(!mini && data == b){
            mini = depth;
            cnt++;
        }
        if(isPossible(data - 1)){
            q.push({data - 1, depth + 1});
        }
        if(isPossible(data + 1)){
            q.push({data + 1, depth + 1});
        }
        if(isPossible(data * 2)){
            q.push({data * 2, depth + 1});
        }
    }
    result = mini;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    q.push({a, 0});
    bfs_visited[a] = true;
    bfs(a);
    cout << result << '\n' << cnt;
}
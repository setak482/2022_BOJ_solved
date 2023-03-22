#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
queue<pair<int, int>> q;
bool bfs_visited[100001];
int parent[100001] = {INF, };
deque<int> mem;
int a, b, result;
bool isPossible(int n){
    if (n < 0 || n > 100000 || bfs_visited[n])
		return false;
	return true;
}
void bfs() {
    while(!q.empty()){
        int data = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(data == b){
            int idx = data;
            while(idx != a){
                mem.push_front(idx);
                idx = parent[idx];
            }
            mem.push_front(a);
            result = depth;
            break;
        }
        if(isPossible(data * 2)){
            q.push({data * 2, depth + 1});
            bfs_visited[data * 2] = true;
            parent[data * 2] = data;
        }
        if(isPossible(data + 1)){
            q.push({data + 1, depth + 1});
            bfs_visited[data + 1] = true;
            parent[data + 1] = data; 
        }
        if(isPossible(data - 1)){
            q.push({data - 1, depth + 1});
            bfs_visited[data - 1] = true;
            parent[data - 1] = data;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    q.push({a, 0});
    bfs_visited[a] = true;
    bfs();

    cout << result << '\n';
    for(auto& i : mem) cout << i << ' ';
}
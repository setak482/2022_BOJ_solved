#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
bool bfs_visited[100001];
int a, b, result;

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
        if(data == b){
            result = depth;
            break;
        }
        if(isPossible(data - 1)){
            bfs_visited[data - 1] = true;
            q.push({data - 1, depth + 1});
        }
        if(isPossible(data + 1)){
            bfs_visited[data + 1] = true;
            q.push({data + 1, depth + 1});
        }
        if(isPossible(data * 2)){
            bfs_visited[data * 1] = true;
            q.push({data * 2, depth + 1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    q.push({a, 0});
    bfs_visited[a] = true;
    bfs(a);

    cout << result;
}
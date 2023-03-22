#include <bits/stdc++.h>
#define MAX 1000002
using namespace std;
bool visited[MAX];
int floar, start, goal, up, down;
bool isPossible(int a){
    if(a > floar || a <= 0 || visited[a]){
        return false;
    }
    return true;
}
void bfs(){
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, 0});
    while(!q.empty()){
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(cur == goal){
            cout << depth;
            return;
        }
        if(isPossible(cur+up)){
            visited[cur+up] = true;
            q.push({cur+up, depth+1});
        }
        if(isPossible(cur-down)){
            visited[cur-down] = true;
            q.push({cur-down, depth+1});
        }
    }
    cout << "use the stairs";
    return;
}
int main(){
    cin >> floar >> start >> goal >> up >> down;
    bfs();
}
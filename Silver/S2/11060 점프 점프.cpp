#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
int arr[1001];
int N;
bool ispos(int a){
    if(a > N || visited[a]){
        return false;
    }
    return true;
}
int bfs(){
    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({1, 0});
    while(!q.empty()){
        int data = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(data == N) return depth;
        if(arr[data] == 0) continue;
        for(int i = 1; i <= arr[data]; i++){
            if(ispos(data + i)){
                visited[data+i] = true;
                q.push({data+i, depth+1});
            }
        }
    }
    return -1;
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        int temp; cin >> temp;
        arr[i] = temp;
    }
    cout << bfs();
}
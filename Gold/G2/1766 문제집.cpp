#include <bits/stdc++.h>
using namespace std;
vector<int> graph[32001];
int linked[32001];
int vertex, edge;
int main(){
    cin >> vertex >> edge;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < edge; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        linked[b]++;
    }
    for(int i = 1; i <= vertex; i++){
        if(linked[i] == 0){
            q.push(i);
        }
    }
    for(int i = 1; i <= vertex; i++){
        int temp = q.top();
        cout << temp << ' ';
        q.pop();
        for(auto& v : graph[temp]){
            linked[v]--;
            if(linked[v] == 0){
                q.push(v);
            }
        }
    }
}
#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
vector<pp> graph[101];
int linked[101];
int meterial[101][101];
int vertex, edge;
int main(){
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[b].push_back({a, c});
        linked[a]++;
    }
    queue<int> q;
    for(int i = 1; i <= vertex; i++){
        if(linked[i] == 0){
            q.push(i);
            meterial[i][i] = 1; 
        }
    }
    for(int i = 1; i <= vertex; i++){
        int cur = q.front();
        q.pop();
        for(auto& v : graph[cur]){
            for(int i = 1; i <= vertex; i++){
                meterial[v.first][i] += meterial[cur][i] * v.second;
            }
            linked[v.first]--;
            if(linked[v.first] == 0){
                q.push(v.first);
            }
        }
    }
    for(int i = 0; i <= vertex; i++){
        if(meterial[vertex][i]){
            cout << i << ' ' << meterial[vertex][i] << '\n';
        }
    }
}
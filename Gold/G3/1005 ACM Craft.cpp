#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1001];
int items[1001];
int linked[1001];
int vertex, edge;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> vertex >> edge;
        queue<int> q;
        for(int i = 1; i <= vertex; i++){
            cin >> items[i];
        }
        for(int i = 0; i < edge; i++){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            linked[b]++;
        }
        int final_node; cin >> final_node;
        int time[1001] = {0, };
        for(int i = 1; i <= vertex; i++){
            if(linked[i] == 0){
                q.push(i);
            }
        }
        while(linked[final_node] > 0){
            int temp = q.front();
            q.pop();
            for(auto& v : graph[temp]){
                linked[v]--;
                time[v] = max(time[v], time[temp] + items[temp]);
                if(linked[v] == 0){
                    q.push(v);
                }
            }
        }
        cout << time[final_node] + items[final_node] << '\n';
        memset(items, 0, sizeof(items));
        memset(linked, 0, sizeof(linked));
        memset(graph, 0, sizeof(graph));
    }
}
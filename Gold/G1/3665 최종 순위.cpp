#include <bits/stdc++.h>
using namespace std;
bool graph[501][501];
int linked[501];
int vertex, edge;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    for (int i = 0; i < tc; i++) {
        vector<int> vertex_item;
        cin >> vertex;
        for (int j = 0; j < vertex; j++) {
            int a; cin >> a;
            vertex_item.push_back(a);
        }
        for (int j = 0; j < vertex - 1; j++) {
            for (int k = j + 1; k < vertex; k++) {
                graph[vertex_item[j]][vertex_item[k]] = true;
                linked[vertex_item[k]]++;
            }
        }
        cin >> edge;
        for (int j = 0; j < edge; j++) {
            int b, c; cin >> b >> c;
            if (graph[b][c]) {
                graph[b][c] = false;
                linked[c]--;
                graph[c][b] = true;
                linked[b]++;
            }
            else {
                graph[c][b] = false;
                linked[b]--;
                graph[b][c] = true;
                linked[c]++;
            }
        }
        queue<int> q;
        vector<int> res;
        for (int j = 1; j <= vertex; j++) {
            if (linked[j] == 0) {
                q.push(j);
            }
        }
        for (int k = 0; k < vertex; k++) {
            if (q.empty()) {
                cout << "IMPOSSIBLE";
                break;
            }
            if (q.size() > 1) {
                cout << "?" << '\n';
                break;
            }
            int temp = q.front();
            res.push_back(temp);
            q.pop();
            for (int j = 1; j <= vertex; j++) {
                if (graph[temp][j]) {
                    linked[j]--;
                    if (linked[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        if(res.size() == vertex){
            for(auto& g : res){
                cout << g << ' ';
            }
        }
        cout << '\n';
        memset(graph, false, sizeof(graph));
        memset(linked, 0, sizeof(linked));
    }
}
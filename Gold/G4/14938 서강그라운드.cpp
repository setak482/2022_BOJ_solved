#include <bits/stdc++.h>
#define INF 90984343
using namespace std;
int graph[101][101];
int ITEM[101];
int vertex, edge, range;
void floyd(){
    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++){
            for(int k = 1; k <= vertex; k++){
                if (graph[j][k] > graph[j][i] + graph[i][k]) 
                    graph[j][k] = graph[j][i] + graph[i][k];
            }
        }
    }
}
int main(){
    int result = 0;
    cin >> vertex >> range >> edge;
    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++) 
            graph[i][j] = INF;
    }
    for(int i = 1; i <= vertex; i++) 
        cin >> ITEM[i];
    for(int i = 0; i < edge; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    floyd();
    for(int i = 1; i <= vertex; i++){
        int temp = 0;
        for(int j = 1; j <= vertex; j++){
            if(graph[i][j] <= range || i == j)
                temp += ITEM[j];
        }
        result = max(temp, result);
    }
    cout << result;
}
#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
int vertex, edge;
int city[101][101];

void floyd(){
    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++){
            for(int k = 1; k <= vertex; k++){
                if (city[j][k] > city[j][i] + city[i][k]) 
                    city[j][k] = city[j][i] + city[i][k];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> vertex >> edge;
    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++) city[i][j] = INF;
    }
    for(int i = 0; i < edge; i++){
        int a, b, c; cin >> a >> b >> c;
        if(city[a][b] > c) city[a][b] = c;
    }
    floyd();
    for(int i = 1; i <= vertex; i++){
        for(int j = 1; j <= vertex; j++){
            if(city[i][j] == INF || i == j){
                cout << 0 << ' '; continue;
            }
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }
}
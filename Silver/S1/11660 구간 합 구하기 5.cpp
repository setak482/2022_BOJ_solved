#include <bits/stdc++.h>
using namespace std;
int sum[1025][1025];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int tc; cin >> tc;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int b; cin >> b;
            sum[i][j] = b;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) sum[i][j] += sum[i-1][j];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) sum[i][j] += sum[i][j-1];
    }
    for(int i = 0; i < tc; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
    }
}
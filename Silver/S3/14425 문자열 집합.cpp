#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M; cin >> N >> M;
    set<string> S;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        string b; cin >> b;
        S.insert(b);
    }
    for(int i = 0; i < M; i++){
        string c; cin >> c;
        if(S.count(c)){
            cnt++;
        }
    }
    cout << cnt;
}
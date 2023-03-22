#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int visited[15];
void queen(int h){
    bool pos;
    if(h == N){
        cnt++;
        return;
    }
    for(int i = 0; i < N; i++){
        pos = true;
        for(int j = 0; j < h; j++){
            if(visited[j] == i || abs(h-j) == abs(i - visited[j])){
                pos = false;
                break;
            }
        }
        if(pos){
            visited[h] = i;
            queen(h+1);
        }
    }
}
int main(){
    cin >> N;
    cnt = 0;
    queen(0);
    cout << cnt;
}
#include <bits/stdc++.h>
using namespace std;
int cycle[500001];
int find(int x){
    if(x == cycle[x]) return x;
    int y = find(cycle[x]);
    cycle[x] = y;
    return cycle[x];
}
bool compare(int x, int y){
    if(find(x) == find(y)) return true;
    return false;
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x < y) cycle[y] = x;
    else cycle[x] = y;
}
int main(){
    int points, turn; cin >> points >> turn;
    for(int i = 0; i < points; i++){
        cycle[i] = i;
    }
    int gameover = 0;
    for(int i = 1; i <= turn; i++){
        int a, b; cin >> a >> b;
        if(!compare(a, b)){
            merge(a, b);
        }
        else{
            if(gameover == 0){
                gameover = i;
            }
        }
    }
    cout << gameover;
}
#include <bits/stdc++.h>
using namespace std;
int root[100001];
int find(int x){
    if(x == root[x]) return x;
    int y = find(root[x]);
    root[x] = y;
    return root[x];
}
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x < y) root[y] = x;
    else root[x] = y;
}
int main(){
    int gate, plane; cin >> gate >> plane;
    queue<int> input;
    int res = 0;
    for(int i = 1; i <= gate; i++){
        root[i] = i;
    }
    for(int i = 0; i < plane; i++){
        int a; cin >> a;
        input.push(a);
    }
    for(int i = 0; i < plane; i++){
        int b = input.front();
        input.pop();
        int dock = find(b);
        if(dock != 0){
            merge(dock, dock-1);
            res++;
        }
        else break;
    }
    cout << res;
}
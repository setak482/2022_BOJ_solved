#include <bits/stdc++.h>
using namespace std;
int root[1000001];
int cmd_f(int x){
    if(x == root[x]) return x;
    int y = cmd_f(root[x]);
    root[x] = y;
    return root[x];
}
void cmd_c(int x, int y){
    if(cmd_f(x) == cmd_f(y)){
        cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';
}
void cmd_u(int x, int y){
    x = cmd_f(x);
    y = cmd_f(y);
    if(x == y) return;
    if(x < y) root[y] = x;
    else root[x] = y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int nums, cmds; cin >> nums >> cmds;
    for(int i = 1; i <= nums; i++){
        root[i] = i;
    }
    while(cmds--){
        int a, b, c; cin >> a >> b >> c;
        if(a == 0) cmd_u(b, c);
        else cmd_c(b, c);
    }
    for(int i = 0; i <= nums; i++) cout << root[i] << ' ';
}
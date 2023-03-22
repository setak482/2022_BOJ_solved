#include <bits/stdc++.h>
using namespace std;
vector<int> s(9, 0);
int p, q;
bool dfs_visited[9];

void dfs(int idx, int current) {
    if(current == q){
        for(int i = 0; i < q; i++){
            cout << s[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i = idx; i <= p; i++){
            if(!dfs_visited[i]){
                dfs_visited[i] = true;
                s[current] = i;
                dfs(i+1, current+1);
                dfs_visited[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin >> p >> q;
    dfs(1,0);
}
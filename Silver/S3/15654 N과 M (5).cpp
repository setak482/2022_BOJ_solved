#include <bits/stdc++.h>
using namespace std;
vector<int> s(9, 0);
vector<int> a;
int p, q;
bool dfs_visited[9];

void dfs(int current) {
    if(current == q){
        for(int i = 0; i < q; i++){
            cout << s[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i = 1; i <= p; i++){
            if(!dfs_visited[i]){
                dfs_visited[i] = true;
                s[current] = a[i];
                dfs(current+1);
                dfs_visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> p >> q;
    a.push_back(0);
    for(int i = 0; i < p; i++){
        int d; cin >> d;
        a.push_back(d);
    }
    sort(a.begin(), a.end());
    dfs(0);
}
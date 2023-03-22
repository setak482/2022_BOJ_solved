#include <bits/stdc++.h>
using namespace std;
vector<int> s(9, 0);
vector<int> a;
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
                s[current] = a[i];
                dfs(i, current+1);
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
    dfs(1, 0);
}
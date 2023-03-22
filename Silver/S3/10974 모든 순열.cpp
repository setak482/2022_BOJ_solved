#include <bits/stdc++.h>
using namespace std;
vector<int> per(9, 0);
int p;
bool dfs_visited[9];

void dfs(int current){
    if(current == p){
        for(int i = 0; i < p; i++){
            cout << per[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i = 1; i <= p; i++){
            if(!dfs_visited[i]){
                dfs_visited[i] = true;
                per[current] = i;
                dfs(current+1);
                dfs_visited[i] = false;
            }
        }
    }
}
int main(){
    cin >> p;
    dfs(0);
}
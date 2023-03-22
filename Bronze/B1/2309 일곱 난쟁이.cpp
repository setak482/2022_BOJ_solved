#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int> nanj_height;
vector<int> memo(10);
bool dfs_visited[10];
bool exits = false;
int p, q;
int sum(vector<int> a){
    int result = 0;
    for(int i = 0; i < 7; i++){
        result += memo[i];
    }
    return result;
}

void dfs(int idx, int current){
    int result = 0;
    if(current == 7){
        if(sum(memo) == 100){
            for(int i = 0; i < 7; i++){
                cout << memo[i] << ' ';
            }
            cout << endl;
            exits = true;
        }
        return;
    }
    else{
        if(exits == false){
            for(int i = idx; i < 9; i++){
                if(!dfs_visited[i]){
                    dfs_visited[i] = true;
                    memo[current] = nanj_height[i];
                    dfs(i+1, current+1);
                    dfs_visited[i] = false;
                }
            }
        }
        else{
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0; i < 9; i++){
        int a; cin >> a;
        nanj_height.push_back(a);
    }
    stable_sort(nanj_height.begin(),nanj_height.end());
    dfs(0, 0);
}
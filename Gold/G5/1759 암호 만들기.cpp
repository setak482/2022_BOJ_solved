#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<char> alph;
vector<char> pw(16);
bool dfs_visited[16];
int p, q;

bool alright(){
    int cnt = 0;
    for(int i = 0; i < q; i++){
        if(pw[i] == 'a'||
           pw[i] == 'e'||
           pw[i] == 'i'||
           pw[i] == 'o'||
           pw[i] == 'u'){
            cnt++;
        }
    }
    if(cnt >= 1 && (p - cnt) >= 2){
        return true;
    }
    return false;
}

void dfs(int idx, int current){
    if(current == p){
        if(alright()){
            for(int i = 0; i < p; i++){
                cout << pw[i];
            }
            cout << endl;
        }
        return;
    }
    else{
        for(int i = idx; i < q; i++){
            if(!dfs_visited[i]){
                dfs_visited[i] = true;
                pw[current] = alph[i];
                dfs(i+1, current+1);
                dfs_visited[i] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> p >> q;
    for(int i = 0; i < q; i++){
        char a; cin >> a;
        alph.push_back(a);
    }
    stable_sort(alph.begin(),alph.end());
    dfs(0, 0);
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> s(9, 0);
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
                s[current] = i;
                dfs(current+1);
                dfs_visited[i] = false;
            }
        }
    }
}

int main(){
    cin >> p >> q;
    dfs(0);
}
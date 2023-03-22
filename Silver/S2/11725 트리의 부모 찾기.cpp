#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> m;
int main(){
    int trsiz; cin >> trsiz;
    for(int i = 0; i < trsiz-1; i++){
        int a, b; cin >> a >> b;
        if(!m.count(a)){
            m.insert({a, {b}});
        }
        else{
            m[a].push_back(b);
        }
        if(!m.count(b)){
            m.insert({b, {a}});
        }
        else{
            m[b].push_back(a);
        }
    }
    vector<int> arr(trsiz+1);
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto& i : m[cur]){
            if(arr[i] == 0){
                arr[i] = cur;
                q.push(i);
            }
        }
    }
    for(int i = 2; i <= trsiz; i++){
        cout << arr[i] << '\n';
    }
}
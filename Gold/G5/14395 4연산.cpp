#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll s, e;
set<ll> visited;
void bfs(){
    queue<pair<ll, string>> q;
    visited.insert(s);
    q.push({s, ""});
    while(!q.empty()){
        ll cur = q.front().first;
        string calc = q.front().second;
        q.pop();
        if(cur == e){
            if(calc == ""){
                cout << 0;
                return;
            }
            else{
                cout << calc;
                return;
            }
        }
        if(!visited.count(cur*cur)){
            visited.insert(cur * cur);
            q.push({cur*cur, calc + '*'});
        }
        if(!visited.count(cur * 2)){
            visited.insert(cur * 2);
            q.push({cur * 2, calc + '+'});
        }
        if(!visited.count(0)){
            visited.insert(0);
            q.push({0, calc + '-'});
        }
        if(cur != 0){
            if(!visited.count(1)){
                visited.insert(1);
                q.push({1, calc + '/'});
            }
        }
    }
    cout << -1;
    return;
}

int main(){
    cin >> s >> e;
    bfs();
}
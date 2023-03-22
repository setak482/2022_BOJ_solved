#include <bits/stdc++.h>
#define ll long long
using namespace std;
queue<pair<ll, int>> q;
ll a, b, result;

bool isPossible(ll n){
    if (n < 0 || n > b)
		return false;
	return true;
}

void bfs() {
    q.push({a, 1});
    while(!q.empty()){
        ll data = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(data == b){
            result = depth;
            break;
        }
        if(isPossible(data * 2)){
            q.push({data * 2, depth + 1});
        }
        if(isPossible((data * 10) + 1)){
            q.push({(data * 10) + 1, depth + 1});
        }
    }
    if(result == 0) result = -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    bfs();
    cout << result;
}
#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b){
        if(a.first.first != b.first.first){
            return a.first.first > b.first.first;
        }
        else{
            return a.second > b.second;
        }
    }
};
int main(){
    int tc; cin >> tc;
    priority_queue<pair<pair<int, string>, int>, vector<pair<pair<int, string>, int>>, cmp> pq;
    for(int i = 0; i < tc; i++){
        int a; string b; cin >> a >> b;
        pq.push({{a, b}, i});
    }
    while(!pq.empty()){
        cout << pq.top().first.first << ' ' << pq.top().first.second << '\n';
        pq.pop();
    }
}
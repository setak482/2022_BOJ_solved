#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct cmp{
    bool operator()(const pair<int, ll> &a, const pair<int, ll> &b){
        return a.second > b.second;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<pair<int, ll> , vector<pair<int, ll>>, cmp> pq;
    vector<ll> arr;
    int n, r; cin >> n >> r;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        pq.push({i, arr[i]});
        while(pq.top().first < i - r + 1){
            pq.pop();
        }
        cout << pq.top().second << ' ';
    }
}   
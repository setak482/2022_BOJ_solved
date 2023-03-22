#include <bits/stdc++.h>
#define INF 1000000001
#define ll long long
using namespace std;
ll init(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end){
    if(begin == end) return tree[node] = arr[begin];
    int mid = (begin+end)/2;
    return tree[node] = min(init(arr, tree, node*2, begin, mid), init(arr, tree, node*2+1, mid+1, end));
}
ll sum(vector<ll> &tree, int node, int begin, int end, int L, int R){
    if(L > end || R < begin){
        return INF;
    }
    if(L <= begin && end <= R){
        return tree[node];
    }
    return min(sum(tree, node*2, begin, (begin+end)/2, L, R), sum(tree, node*2+1, (begin+end)/2+1, end, L, R));
}
ll update(vector<ll> &tree, int node, int begin, int end, int idx, ll change){
    if(idx < begin || idx > end) return tree[node];
    if(begin == end) return tree[node] = change;
    int mid = (begin+end)/2;
    ll L = update(tree, node*2, begin, mid, idx, change);
    ll R = update(tree, node*2+1, mid+1, end, idx, change);
    return tree[node] = min(L, R);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll c; cin >> c;
        arr.push_back(c);
    }
    int height = int(ceil(log2(n)));
    int tree_size = 1 << (height + 1);
    vector<ll> tree(tree_size);
    init(arr, tree, 1, 0, n-1);
    int tc; cin >> tc;
    for(int i = 0; i < tc; i++){
        int cmd; cin >> cmd;
        if(cmd == 2){
            int b, c; cin >> b >> c;
            cout << sum(tree, 1, 0, n-1, b-1, c-1) << '\n';
        }
        else{
            int b, c; cin >> b >> c;
            b--;
            update(tree, 1, 0, n-1, b, c);
        }
    }
}
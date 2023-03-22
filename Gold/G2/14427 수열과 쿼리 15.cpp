#include <bits/stdc++.h>
#define INF INT_MAX
#define ll long long
using namespace std;
int minindex(vector<ll> &arr, int x, int y){
    if(arr[x] == arr[y]) return x < y ? x : y;
    return arr[x] < arr[y] ? x : y;
}
ll init(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end){
    if(begin == end) return tree[node] = begin;
    int mid = (begin+end)/2;
    return tree[node] = minindex(arr, init(arr, tree, node*2, begin, mid), init(arr, tree, node*2+1, mid+1, end));
}
int update(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end, int idx){
    if(idx < begin || idx > end || begin == end) return tree[node];
    return tree[node] = minindex(arr ,update(arr, tree, node*2, begin, (begin+end)/2, idx), update(arr, tree, node*2+1, ((begin+end)/2)+1, end, idx));
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
            cout << tree[1]+1 << '\n';
        }
        else{
            int b, c; cin >> b >> c;
            b--;
            arr[b] = c;
            update(arr, tree, 1, 0, n-1, b);
        }
    }
}
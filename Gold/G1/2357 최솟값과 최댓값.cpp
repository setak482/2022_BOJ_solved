#include <bits/stdc++.h>
#define INF INT_MAX
#define ll long long
using namespace std;
ll max_init(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end){
    if(begin == end){
        return tree[node] = arr[begin];
    }
    else{
        return tree[node] = max(max_init(arr, tree, node*2, begin, (begin+end)/2),
            max_init(arr, tree, node*2+1, (begin+end)/2+1, end));
    }
}
ll findmax(vector<ll> &tree, int node, int begin, int end, int L, int R){
    if(L > end || R < begin){
        return 0;
    }
    if(L <= begin && end <= R){
        return tree[node];
    }
    return max(findmax(tree, node*2, begin, (begin+end)/2, L, R),
        findmax(tree, node*2+1, (begin+end)/2+1, end, L, R));
}
ll min_init(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end){
    if(begin == end){
        return tree[node] = arr[begin];
    }
    else{
        return tree[node] = min(min_init(arr, tree, node*2, begin, (begin+end)/2),
            min_init(arr, tree, node*2+1, (begin+end)/2+1, end));
    }
}
ll findmin(vector<ll> &tree, int node, int begin, int end, int L, int R){
    if(L > end || R < begin){
        return INF;
    }
    if(L <= begin && end <= R){
        return tree[node];
    }
    return min(findmin(tree, node*2, begin, (begin+end)/2, L, R),
        findmin(tree, node*2+1, (begin+end)/2+1, end, L, R));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll c; cin >> c;
        arr.push_back(c);
    }
    int height = int(ceil(log2(n)));
    int tree_size = 1 << (height + 1);
    vector<ll> maxtree(tree_size);
    vector<ll> mintree(tree_size);
    min_init(arr, mintree, 1, 0, n-1);
    max_init(arr, maxtree, 1, 0, n-1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        cout << findmin(mintree, 1, 0, n-1, a-1, b-1) << ' ';
        cout << findmax(maxtree, 1, 0, n-1, a-1, b-1) << '\n';
    }
}
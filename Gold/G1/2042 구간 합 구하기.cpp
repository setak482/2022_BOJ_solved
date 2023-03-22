#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll init(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end){
    if(begin == end){
        return tree[node] = arr[begin];
    }
    else{
        return tree[node] = init(arr, tree, node*2, begin, (begin+end)/2) +
            init(arr, tree, node*2+1, (begin+end)/2+1, end);
    }
}
ll sum(vector<ll> &tree, int node, int begin, int end, int L, int R){
    if(L > end || R < begin){
        return 0;
    }
    if(L <= begin && end <= R){
        return tree[node];
    }
    return sum(tree, node*2, begin, (begin+end)/2, L, R) + 
        sum(tree, node*2+1, (begin+end)/2+1, end, L, R);
}
void update(vector<ll> &tree, int node, int begin, int end, int idx, ll change){
    if(idx < begin || idx > end) return;
    tree[node] = tree[node] + change;
    if(begin != end){
        update(tree, node*2, begin, (begin + end)/2, idx, change);
        update(tree, node*2+1, (begin + end)/2+1, end, idx, change);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll c; cin >> c;
        arr.push_back(c);
    }
    int height = int(ceil(log2(n)));
    int tree_size = int(pow(2, height+1)-1);
    vector<ll> tree(tree_size);
    init(arr, tree, 1, 0, n-1);
    for(int i = 0; i < m+k; i++){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int a; ll b;
            cin >> a >> b;
            ll c = b - arr[a-1]; arr[a-1] = b;
            update(tree, 1, 0, n-1, a-1, c);
        }
        else if(cmd == 2){
            int a, b; cin >> a >> b;
            cout << sum(tree, 1, 0, n-1, a-1, b-1) << '\n';
        }
    }
}
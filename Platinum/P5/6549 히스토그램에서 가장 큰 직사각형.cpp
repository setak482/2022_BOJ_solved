#include <bits/stdc++.h>
#define INF INT_MAX
#define ll long long
using namespace std;
int n;
int minindex(vector<ll> &arr, int x, int y){
    if(arr[x] == arr[y]) return x < y ? x : y;
    return arr[x] < arr[y] ? x : y;
}
ll init(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end){
    if(begin == end) return tree[node] = begin;
    int mid = (begin+end)/2;
    return tree[node] = minindex(arr, init(arr, tree, node*2, begin, mid), init(arr, tree, node*2+1, mid+1, end));
}
ll findmin(vector<ll> &arr, vector<ll> &tree, int node, int begin, int end, int L, int R){
    if(L > end || R < begin){
        return -1;
    }
    if(L <= begin && end <= R){
        return tree[node];
    }
    int mid = (begin + end) / 2;
    int l_idx = findmin(arr, tree, node*2, begin, mid, L, R);
    int r_idx = findmin(arr, tree, node*2 + 1, mid+1, end, L, R);
    if(l_idx == -1) return r_idx;
    if(r_idx == -1) return l_idx;
    return minindex(arr, l_idx, r_idx);
}
ll two_pointer(vector<ll> &arr, vector<ll> &tree, int hajimari, int owari){
    int mindex = findmin(arr, tree, 1, 0, n-1, hajimari, owari);
    ll res = (ll)(owari - hajimari + 1) * (ll)arr[mindex];
    if(hajimari <= mindex - 1){
        ll L_res = two_pointer(arr, tree, hajimari, mindex - 1);
        res = max(res, L_res);
    }
    if(owari >= mindex + 1){
        ll R_res = two_pointer(arr, tree, mindex + 1, owari);
        res = max(res, R_res);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    n = -1;
    while(true){
        cin >> n;
        if(n == 0) return 0;
        vector<ll> arr;
        for(int i = 0; i < n; i++){
            ll c; cin >> c;
            arr.push_back(c);
        }
        int height = int(ceil(log2(n)));
        int tree_size = 1 << (height + 1);
        vector<ll> tree(tree_size);
        init(arr, tree, 1, 0, n-1);
        cout << two_pointer(arr, tree, 0, n-1) << '\n';
    }
}
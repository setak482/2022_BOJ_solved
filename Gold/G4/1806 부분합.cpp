#include <bits/stdc++.h>
#define INF 999999999
#define ll long long
using namespace std;
int main(){
    ll point, sum = 0;
    int min_len = INF;
    int N; cin >> N >> point;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    int left = 0, right = 0;
    int siz = v.size();
    while(right <= N){
        if(sum >= point){
            min_len = min(min_len, right-left);
        }
        if(sum <= point && right <= siz){
            sum += v[right];
            right++;
        }
        else if(sum > point || right >= siz){
            sum -= v[left];
            left++;
        }
    }
    if(min_len != INF) cout << min_len;
    else cout << 0;
}
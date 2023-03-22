#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    for(int t = 0; t < tc; t++){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int input_size; cin >> input_size;
        for(int i = 0; i < input_size; i++){
            ll temp; cin >> temp;
            pq.push(temp);
        }
        ll result_A = 0, result_B = 0;
        while(pq.size() > 1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            result_A = a + b;
            pq.push(result_A);
            result_B += result_A;
        }
        cout << result_B << '\n';
        pq.pop();
    }
}
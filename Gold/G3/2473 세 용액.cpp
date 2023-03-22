#include <bits/stdc++.h>
#define ll long long
#define INF 5000000000001
using namespace std;
ll L, R, M;
ll result = INF;
int main(){
    int N; cin >> N;
    vector<ll> arr;
    for(int i = 0; i < N; i++){
        ll a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int Lp = 0, Mp = 1, Rp = arr.size()-1;
    while(Lp <= N-3 || result != 0){
        if(Lp == N-2) break;
        if(Mp >= Rp){
            Lp++;
            Mp = Lp+1;
            Rp = arr.size()-1;
            continue;
        }
        ll temp = arr[Lp] + arr[Mp] + arr[Rp];
        if(result > abs(temp)){
            L = arr[Lp];
            M = arr[Mp];
            R = arr[Rp];
            result = abs(temp);
        }
        if(temp == 0) break;
        if(temp < 0) Mp++;
        else Rp--;
    }
    cout << L << ' ' << M << ' ' << R;
}
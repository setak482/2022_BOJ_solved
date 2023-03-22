#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main(){
    ll result = 0;
    priority_queue<ll> pq_1;
    vector<pair<ll, ll>> bosukarr;
    vector<int> gabans;
    int bosuk, gaban; cin >> bosuk >> gaban;
    for(int i = 0; i < bosuk; i++){
        ll a, b; cin >> a >> b;
        bosukarr.push_back({a, b});
    }
    for(int i = 0; i < gaban; i++){
        int a; cin >> a;
        gabans.push_back(a);
    }
    sort(bosukarr.begin(), bosukarr.end());
    sort(gabans.begin(), gabans.end());
    int idx = 0;
    for(int i = 0; i < gaban; i++){
        int a = gabans[i];
        while(bosukarr[idx].first <= a && idx < bosuk){
            pq_1.push(bosukarr[idx++].second);
        }
        if(!pq_1.empty()){
            result += pq_1.top();
            pq_1.pop();
        }
    }
    cout << result;
}
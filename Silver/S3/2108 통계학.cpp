#include <bits/stdc++.h>
#define INF 987412365
using namespace std;
int mode[8001];
int main(){
    int siz; cin >> siz;
    vector<int> v;
    int sum = 0; 
    int little = INF, big = INF;
    for(int i = 0; i < siz; i++){
        int a; cin >> a;
        if(little == INF) little = a;
        else if(a < little) little = a;
        if(big == INF) big = a;
        else if(big < a) big = a;
        sum += a;
        mode[a+4000]++;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int max_mode = 0;
    for(int i = 0; i <= 8000; i++){
        max_mode = max(max_mode, mode[i]);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i <= 8000; i++){
        if(mode[i] == max_mode){
            pq.push(i-4000);
        }
    }
    int aver = round(double(sum)/siz);
    if(aver == 0) cout << 0;
    else cout << aver;
    cout << '\n' << v[(siz-1)/2];
    if(pq.size() == 1) cout << '\n' << pq.top();
    else{
        pq.pop();
        cout << '\n' << pq.top();
    }
    cout << '\n' << abs(big - little);
}
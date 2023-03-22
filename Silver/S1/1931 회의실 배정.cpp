#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    int endtime, cnt = 0;
    int tc; cin >> tc;
    vector<pair<int, int>> pv;
    vector<int> pvfinder;
    for(int i = 0; i < tc; i++){
        int a, b; cin >> a >> b;
        pv.push_back(make_pair(a, b));
    }
    stable_sort(pv.begin(), pv.end(), cmp);
    for(int i = 0; i < tc; i++){
        if(i == 0){
            cnt++;
            endtime = pv[0].second;
            continue;
        }
        else if(pv[i].first >= endtime){
            cnt++;
            endtime = pv[i].second;
        }
    }
    // for(auto& i : pv){
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    cout << cnt;
}
#include <bits/stdc++.h>
using namespace std;
bool bigger(string a, string b){ // sort는 오름차순이 기본
    if(a==b) return true;
    return a + b > b + a;
}
bool zero(vector<string> &v){
    for(auto& i : v){
        if(i != "0") return false;
    }
    return true;
}
int main(){
    int tc; cin >> tc;
    vector<string> arr;
    for(int i = 0; i < tc; i++){
        string a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end(), bigger);
    if(!zero(arr)) for(auto& i : arr) cout << i;
    else cout << 0;
}
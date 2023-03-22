#include <bits/stdc++.h>
using namespace std;
set<string> visited;
string s, e;
void dfs(string str){
    if(str == s){
        cout << 1;
        exit(0);
    }
    if(str.size() <= s.size()) return;
    if(str.back() == 'A'){
        string new_ = str;
        new_.pop_back();
        dfs(new_);
    }
    if(str.front() == 'B'){
        string new_ = str;
        reverse(new_.begin(), new_.end());
        new_.pop_back();
        dfs(new_);
    }
}
int main(){
    cin >> s >> e;
    dfs(e);
    cout << 0;
}
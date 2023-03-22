#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    stack<int> stk;
    for(int i = 0; i < tc; i++){
        string cmd; cin >> cmd;
        if(cmd == "push"){
            int a; cin >> a; stk.push(a);
        }
        else if(cmd == "pop"){
            if(stk.empty()){
                cout << "-1\n";
                continue;
            }
            cout << stk.top() << '\n';
            stk.pop();
        }
        else if(cmd == "size"){
            cout << stk.size() << '\n';
        }
        else if(cmd == "empty"){
            cout << stk.empty() << '\n';
        }
        else if(cmd == "top"){
            if(stk.empty()){
                cout << "-1\n";
                continue;
            }
            cout << stk.top() << '\n';
        }
    }
}
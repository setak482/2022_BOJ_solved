#include <bits/stdc++.h>
using namespace std;
int main(){
    int tc; cin >> tc;
    vector<string> inventory;
    bool result = true;
    for(int i = 0; i < tc+1; i++){
        string vps;
        getline(cin, vps);
        inventory.push_back(vps);
    }
    inventory.erase(inventory.begin());
    for(auto& i : inventory){
        stack<int> s;
        result = true;
        for(auto& v : i){
            if(v == '('){
                s.push(1);
            }
            else if(!s.empty() && v == ')'){
                s.pop();
            }
            else if(s.empty() && v == ')'){
                result = false;
                goto END;
            }
        }
        if(s.size() != 0){
            result = false;
        }
END:
        if(result){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}
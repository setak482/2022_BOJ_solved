#include <bits/stdc++.h>
using namespace std;
int main(){
    string entire, bomb; cin >> entire >> bomb;
    reverse(bomb.begin(), bomb.end());
    int bomb_len = bomb.size();
    string result;
    for(auto& c : entire){
        result.push_back(c);
        if(result.size() < bomb_len) continue;
        if(result.back() == bomb.front()){
            string temp;
            for(int i = result.size()-1; i != result.size()-bomb_len-1; i--){
                temp.push_back(result[i]);
            }
            if(temp == bomb){
                for(int i = 0; i < temp.size(); i++){
                    result.pop_back();
                }
            }
        }
    }
    reverse(bomb.begin(), bomb.end());
    if(result.empty()) cout << "FRULA";
    else cout << result;
}
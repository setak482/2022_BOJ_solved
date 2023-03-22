#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int tc; cin >> tc;
    ll result = 0;
    deque<int> v;
    for(int i = 0; i < tc; i++){
        int c; cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int max_size = v.size();
    for(int i = 0; i < max_size; i++){
        int a = 0, b = 0;
        if(v.empty()) break;
        a = v.front(); v.pop_front();
        if(v.size() >= 1){
            b = v.front();
            if(b > 1){
                result += a * b; v.pop_front(); 
            }
            else if(b == 1){
                result += a;
            }
            else if(b == 0){
                result += a; 
            }
            else if(a > 0 && b < 0){
                result += a;
            }
            else if(a == 0 && b < 0 && v.size() % 2 != 0){
                result += a * b; v.pop_front();
            }
            else if(a == 0 && b < 0 && v.size() % 2 == 0){
                result += a;
            }
            else if(a < 0 && b < 0 && v.size() % 2 != 0){
                result += a * b; v.pop_front();
            }
            else if(a < 0 && b < 0 && v.size() % 2 == 0){
                result += a;
            }
            else{
                result += a; 
            }
        }
        else{
            result += a;
            break;
        }
    }
    cout << result;
}
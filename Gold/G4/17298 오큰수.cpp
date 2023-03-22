#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    int temp; cin >> temp;
    for(int i = 0; i < temp; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    stack<int> s;
    stack<int> ans;
    s.push(arr[temp-1]);
    int pos = temp-2;
    ans.push(-1);
    while(pos >= 0){
        if(s.top() > arr[pos]){
            ans.push(s.top());
            s.push(arr[pos]);
        }
        else{
            while(!s.empty()){
                if(s.top() <= arr[pos]) s.pop();
                else{
                    ans.push(s.top());
                    break;
                }
            }
            if(s.empty()) ans.push(-1);
            s.push(arr[pos]);
        }
        pos--;
    }
    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> arr;
    int nums; cin >> nums;
    for(int i = 0; i < nums; i++){
        int a; cin >> a;
        arr.push(a);
    }
    int result = 0;
    while(!arr.empty()){
        if(result+1 >= arr.top()){
            result += arr.top();
            arr.pop();
        }
        else break;
    }
    cout << result+1;
}
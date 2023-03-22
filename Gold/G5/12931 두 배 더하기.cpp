#include <bits/stdc++.h>
using namespace std;
bool isDouble(vector<int> &v){
    for(auto& i : v){
        if(i % 2 != 0) return false;
    }
    return true;
}
bool isAllZero(vector<int> &v){
    for(auto& i : v){
        if(i != 0) return false;
    }
    return true;
}
int main(){
    int arr_size; cin >> arr_size;
    vector<int> arr;
    for(int i = 0; i < arr_size; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    int cnt = 0;
    while(!isAllZero(arr)){
        if(isDouble(arr)){
            for(int i = 0; i < arr.size(); i++){
                arr[i] /= 2;
            }
            cnt++;
        }
        else{
            for(int i = 0; i < arr.size(); i++){
                if(arr[i] % 2 != 0){
                    arr[i] -= 1;
                    cnt++;  // 1 감소할때마다 cnt 증가시키는게 핵심
                }
            }
        }
    }
    cout << cnt;
}
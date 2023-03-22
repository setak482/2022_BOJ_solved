#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K; cin >> N >> K;
    vector<int> nums;
    vector<int> new_nums;
    for(int i = 0; i < N; i++){
        int a; scanf("%1d", &a);
        nums.push_back(a);
    }
    for(int i = 0; i < nums.size(); i++){
        if(new_nums.empty()) new_nums.push_back(nums[i]);
        else{
            while(!new_nums.empty() && new_nums.back() < nums[i] && K){
                new_nums.pop_back();
                K--;
            }
            new_nums.push_back(nums[i]);
        }
    }
    for(int i = 0; i < new_nums.size() - K; i++){
        cout << new_nums[i];
    }
}
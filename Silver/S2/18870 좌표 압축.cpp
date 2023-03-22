#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<int> arr;
    vector<int> pivot;
    vector<int> new_arr;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        int b; cin >> b;
        arr.push_back(b);
    }
    pivot = arr;
    sort(pivot.begin(), pivot.end());
    pivot.erase(unique(pivot.begin(), pivot.end()), pivot.end());
    for(auto& i : arr){
        new_arr.push_back(lower_bound(pivot.begin(), pivot.end(), i) - pivot.begin());
    }
    for(auto& i : new_arr){
        cout << i << ' ';
    }
}
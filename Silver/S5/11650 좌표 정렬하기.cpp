#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sizing;
    cin >> sizing;
    vector<pair<int, int>> pair_vec;
    for(int i = 0; i < sizing; i++){
        int a, b;
        cin >> a >> b;
        pair_vec.push_back(pair<int, int>(a, b));
    }
    sort(pair_vec.begin(), pair_vec.end());
    for(auto& i : pair_vec){
        cout << i.first << " " << i.second << '\n';
    }
}
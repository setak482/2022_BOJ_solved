#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        multiset<int, greater<int>> pq;
        int cnt = 0;
        int order; cin >> order;
        while(order--){
            char operation; cin >> operation;
            int num; cin >> num;
            if(operation == 'I'){
                pq.insert(num);
            }
            else{
                if(pq.empty()) continue;
                if(num == -1){
                    pq.erase(--pq.end());
                }
                else{
                    pq.erase(pq.begin());
                }
            }
        }
        if(pq.size() <= 0){
            cout << "EMPTY" << endl;
        }
        else{
            cout << *pq.begin() << ' ' << *pq.rbegin() << endl;
        }
    }
}
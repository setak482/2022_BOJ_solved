#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> q;
    int size; cin >> size;
    for(int i = 1; i < size+1; i++){
        q.push_back(i);
    }
    while(q.size() != 1){
        q.pop_front();
        int b = q.front();
        q.push_back(b);
        q.pop_front();
    }
    cout << q.front();
}
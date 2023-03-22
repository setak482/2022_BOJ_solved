#include <iostream>
#include <deque>
using namespace std;
int main(){
    int testcase;
    cin >> testcase;
    deque<int> result;
    for(int i = 0; i < testcase; i++){
        int a, b;
        cin >> a >> b;
        result.push_back(a+b);
    }
    for(auto& i : result){
        cout << i << '\n';
    }
}
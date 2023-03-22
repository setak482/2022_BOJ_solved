#include <iostream>
using namespace std;
int main(){
    int d[42] = {};
    int cnt = 0;
    for(int i = 0; i < 10; i++){
        int a;
        cin >> a;
        d[a % 42]++;
    }
    for(auto i : d){
        if(i > 0){
            cnt++;
        }
    }
    cout << cnt;
}
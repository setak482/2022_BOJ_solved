#include <iostream>
using namespace std;
int main(){
    int a, cnt = 0;
    cin >> a;
    for (int i = 1; a > i; i += cnt*6){
        cnt++;
    }
    if(a == 1){
        cnt = 0;
    }
    cout << cnt + 1;
}
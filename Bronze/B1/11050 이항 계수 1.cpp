#include <iostream>
using namespace std;
int main(){
    int a, b, c = 1, d = 1, e;
    cin >> a >> b;
    e = b;
    for(int i = 0; i < b; i++){
        c *= a;
        d *= e;
        a--;
        e--;
    }
    cout << c / d;
}
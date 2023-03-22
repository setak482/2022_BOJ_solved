#include <iostream>
using namespace std;
int main(){
    int result = 0;
    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        result += a * a;
    }
    cout << result % 10;
}
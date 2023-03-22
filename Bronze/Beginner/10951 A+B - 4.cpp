#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;
int main(){
    queue<int> result;
    int a, b;
    while(cin >> a >> b){
        result.push(int(a)+int(b));
    }
    while(result.empty()){
        cout << result.front() << endl;
        result.pop();
    }
}
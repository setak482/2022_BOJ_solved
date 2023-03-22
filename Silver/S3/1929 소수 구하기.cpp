#include <iostream>
#include <cmath>
using namespace std;

bool prime(int num){
    int a;
    a = int(sqrt(double(num)));
    for(int i = 2; i < a+1; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = a; i < b+1; i++){
        if(i == 1){
            continue;
        }
        else if(i == 2){
            cout << i << "\n";
            continue;
        }
        else if(prime(i)){
            cout << i << "\n";
        }
    }
}
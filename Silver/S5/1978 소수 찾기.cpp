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
    int tc, cnt = 0;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int a;
        cin >> a;
        if(a == 1){
            continue;
        }
        else if(a == 2){
            cnt++;
            continue;
        }
        else{
            if(prime(a)){
                cnt++;
            }
        }
    }
    cout << cnt;
}
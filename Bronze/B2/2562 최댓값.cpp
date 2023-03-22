#include <iostream>
using namespace std;

int main(){
    int max;
    int max_n;
    for(int i = 0; i < 9; i++){
        int b;
        cin >> b;
        if(i == 0){
            max = b;
            max_n = i+1;
        }
        else if(b > max){
            max = b;
            max_n = i+1;
        }
    }
    cout << max << endl << max_n;
}
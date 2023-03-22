#include <iostream>
using namespace std;
int main(){
    int result[8];
    int res = 0;
    int hajimete;
    int curr;
    bool innocent = true;
    for(int i = 0; i < 8; i++){
        int a;
        cin >> a;
        result[i] = a;
    }
    for(int i = 0 ; i < 7; i++){
        if(i == 0){
            hajimete = result[i+1] - result[i];
            continue;
        }
        curr = result[i+1] - result[i];
        if(curr != hajimete){
            innocent = false;
        }
    }
    if(innocent && hajimete == 1){
        cout << "ascending";
    }
    else if(innocent && hajimete == -1){
        cout << "descending";
    }
    else{
        cout << "mixed";
    }
}
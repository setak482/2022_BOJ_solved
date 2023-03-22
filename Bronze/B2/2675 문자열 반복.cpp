#include <iostream>
#include <string>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int a;
        string b;
        cin >> a >> b;
        for(auto& v : b){
            for(int ii = 0; ii < a; ii++){
                cout << v;
            }
        }
        cout << '\n';
    }
}
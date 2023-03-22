#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string a;
    cin >> a;
    for(int alp = 97; alp < 123; alp++){
        for(int i = 0; i < a.size(); i++){
            if(count(a.begin(), a.end(), char(alp))){
                cout << a.find_first_of(char(alp)) << ' ';
                break;
            }
            else{
                cout << -1 << ' ';
                break;
            }
        }
    }
}
#include <iostream>
#include <string>
using namespace std;
int main(){
    int jyu[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a * b * c;
    string e = to_string(d);
    for(int ii = 0; ii < e.size(); ii++){
        int g = stoi(e.substr(ii, 1));
        jyu[g] += 1;
    }
    for(int i = 0; i < 10; i++){
        cout << jyu[i] << '\n';
    }
}
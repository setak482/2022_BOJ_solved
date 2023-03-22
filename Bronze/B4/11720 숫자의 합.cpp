#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    int ctd = 0;
    string b;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        float d = stoi(b.substr(i, 1));
        while (d > 9){
            d = d/10;
            d = int(floor(d));
        }
        d = int(floor(d));
        ctd += d;
    }
    cout << ctd;
}
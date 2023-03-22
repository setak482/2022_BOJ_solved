#include <bits/stdc++.h>
using namespace std;
int main() {
    string origin_text;
    cin >> origin_text;
    string copy_text;
    bool notPPAP = false;
    int Pcount = 0;
    for (int i = 0; i < origin_text.size(); i++) {
        char cur = origin_text[i];
        if(cur == 'P'){
            Pcount++;
            continue;
        }
        if(Pcount >= 2 && origin_text[i+1] == 'P'){
            Pcount--;
            i++;
        }
        else{
            notPPAP = true;
            break;
        }
    }
    if(notPPAP || Pcount != 1) cout << "NP";
    else cout << "PPAP";
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<bool> bit(21, false);
    int testcase;
    cin >> testcase;
    while(testcase--){
        string cmd;
        cin >> cmd;
        if (cmd == "add"){
            int a;
            cin >> a;
            bit[a] = true;
        }
        else if (cmd == "remove"){
            int a;
            cin >> a;
            bit[a] = false;
        }
        else if (cmd == "check"){
            int a;
            cin >> a;
            if(bit[a]){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else if (cmd == "toggle"){
            int a;
            cin >> a;
            bit[a] = !bit[a];
        }
        else if (cmd == "all"){
            fill(bit.begin(), bit.end(), true);
        }
        else if (cmd == "empty"){
            fill(bit.begin(), bit.end(), false);
        }
    }
}
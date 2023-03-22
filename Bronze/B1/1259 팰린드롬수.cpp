#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
    while(1){
        int a;
        bool isPelindrom = true;
        cin >> a;
        if(a == 0){
            return 0;
        }
        string b = to_string(a);
        deque<char> c;
        for(int i = 0; i < b.size(); i++){
            c.push_back(b[i]);
        }
        while(c.size() >= 2){
            if (c.front() != c.back()){
                isPelindrom = false;
                break;
            }
            else{
                c.pop_back();
                c.pop_front();
            }
        }
        if(isPelindrom){
            cout << "yes" << '\n';
        }
        else{
            cout << "no" << '\n';
        }
    }
}
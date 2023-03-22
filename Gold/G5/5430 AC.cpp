#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc; // TESTCASE 입력
    for(int i = 0; i < tc; i++){ 
        int nuj = 0;
        deque<int> tem;
        bool swit = false;
        bool rev = false;
        deque<int> arr;
        string command;
        cin >> command;
        int arrsize;
        cin >> arrsize;
        string arr_text;
        cin >> arr_text;
        for(auto& iii : arr_text){
            if(isdigit(iii)){
                int t;
                t = atoi(&iii);
                while(t > 9){
                    t = t/10;
                }
                tem.push_front(t);
            }
            else if(iii == ',' || iii == ']'){
                int cnt = 0;
                for(auto& iv : tem){
                    nuj += iv * int(round(pow(10, cnt)));
                    cnt++;
                }
                arr.push_back(nuj);
                tem.clear();
                nuj = 0;
            }
        }  
        if(arr_text == "[]"){
            arr.clear();
        }
        for(auto& iv : command){
            if(iv == 'R'){
                rev = !rev;
            }
            else if(iv == 'D'){
                if(!arr.empty()){
                    if(rev == false){
                        arr.pop_front();
                    }
                    else if(rev == true){
                        arr.pop_back();
                    }
                }
                else{
                    cout << "error" << endl;
                    swit = true;
                    break;
                }
            }
        }
        if (swit == false){
            cout << '[';
            for(int vii = 0; vii < arr.size(); vii++){
                if(vii != arr.size()-1){
                    if(rev == false){
                        cout << arr[vii] << ',';
                    }
                    else{
                        cout << arr.at(arr.size()-vii-1) << ',';
                    }
                }
                else{
                    if(rev == false){
                        cout << arr[vii];
                    }
                    else{
                        cout << arr.at(arr.size()-vii-1);
                    }
                }
            }
            cout << ']'<<endl;
        }
    }
}
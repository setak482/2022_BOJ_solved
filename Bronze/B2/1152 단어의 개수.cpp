#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string sentence;
    string word;
    getline(cin, word);

    if(word[0] == ' '){
        word.erase(0,1);
    }
    if(word[word.length()-1] == ' '){
        word.pop_back();
    }

    for(int i = 0; i < word.length(); i++){
        if(i==0){
            continue;
        }
        if(word[i-1] == ' ' && word[i] == ' '){
            word.erase(word.begin()+i-1);
        }
    }

    int count = 0;
    for(int i = 0; i < word.length(); i++){
        if(word[i] == ' '){
            count++;
        }
    }
    if(word == " "){
        count = -1;
    }
    if(word == ""){
        count = -1;
    }
    cout << count+1;
}
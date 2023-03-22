#include <bits/stdc++.h>
#define MAX_SIZE 2001
using namespace std;
bool dp[MAX_SIZE][MAX_SIZE];
int arr[MAX_SIZE];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int num; cin >> num;
    for(int i = 1; i <= num; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= num-i; j++){
            if(arr[j] == arr[j+i]){
                dp[j][j+i] = true;
            }
        }
    }
    for(int i = 3; i < num; i++){
        for(int j = 1; j <= num-i; j++){
            if(arr[j] == arr[j+i] && dp[j+1][j+i-1]){
                dp[j][j+i] = true;
            }
        }
    }
    int prob; cin >> prob;
    for(int i = 0; i < prob; i++){
        int c, d; cin >> c >> d;
        cout << dp[c][d] << '\n';
    }
}
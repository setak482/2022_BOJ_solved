#include <bits/stdc++.h>
using namespace std;
int matrixA[101][101];
int matrixB[101][101];
int AX, AY, BX, BY;
vector<vector<int>> matrix_mult(){
    vector<vector<int>> res(AY, vector<int>(AX, 0));
    for(int i = 0; i < AY; i++){
        for(int ii = 0; ii < BX; ii++){
            int sum = 0;
            for(int iii = 0; iii < max(AY, BX); iii++){
                sum += matrixA[i][iii] * matrixB[iii][ii];
            }
            res[i][ii] = sum;
        }
    }
    return res;
}
void matrix_print(vector<vector<int>> &v){
    for(int i = 0; i < AY; i++){
        for(int ii = 0; ii < BX; ii++){
            cout << v[i][ii] << ' ';
        }
        cout << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> AY >> AX;
    for(int i = 0; i < AY; i++){
        for(int ii = 0; ii < AX; ii++){
            cin >> matrixA[i][ii];
        }
    }
    cin >> BY >> BX;
    for(int i = 0; i < BY; i++){
        for(int ii = 0; ii < BX; ii++){
            cin >> matrixB[i][ii];
        }
    }
    vector<vector<int>> c = matrix_mult();
    matrix_print(c);
}
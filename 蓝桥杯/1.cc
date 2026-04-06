#include <bits/stdc++.h>
using namespace std;
int main() {
    int min = 100000;
    int N, M;
    cin >> N >> M;
    vector<int> B;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int j = 0; j < N;j++){
        for (int i = 1; i < M - 1; i++) {

        }
    }
       
}
int main(){
    int n;
    cin >> n;
    int count = 0;
    vector<vector<char>> B;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n;j++){
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < 2;i++){
        for (int j = 0; j < n;j++){
            if(B[i][j]=='#'){
                if(i==0){
                    if(j==0){
                        B[i + 1][j] = '.';
                        B[i][j + 1] = '.';
                    }else if(j==n-1){
                        B[i + 1][j] = '.';
                        B[i][j - 1] = '.';
                    }else{
                        B[i - 1][j] = '.';
                        B[i + 1][j] = '.';
                        B[i][j - 1] = '.';
                        B[i][j + 1] = '.';
                    }
                }else{
                    if(j==0){
                        B[i - 1][j] = '.';
                        B[i][j + 1] = '.';
                    }else if(j==n-1){
                        B[i - 1][j] = '.';
                        B[i][j + 1] = '.';
                    }else{
                        B[i - 1][j] = '.';
                        B[i + 1][j] = '.';
                        B[i][j - 1] = '.';
                        B[i][j + 1] = '.';
                    }
                }
            }
        }
    }
    for (int i = 0; i < 2;i++){
        for (int j = 0; j < n;j++){
            if(B[i][j]=='.'){
                count++;
            }
        }
    }
    return count;
}
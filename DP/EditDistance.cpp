#include <bits/stdc++.h>
using namespace std;

int Solve(string& str1, string& str2){
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> Dp(n+1,vector<int>(m+1));
    Dp[0][0] = 0;
    for(int i=1;i<=n;i++) Dp[i][0] = i;
    for(int j=1;j<=m;j++) Dp[0][j] = j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                Dp[i][j] = min(Dp[i-1][j-1], 1+min(Dp[i-1][j],Dp[i][j-1]));
            }else{
                Dp[i][j] = 1+min(Dp[i-1][j-1], min(Dp[i-1][j],Dp[i][j-1]));
            }
        }
    } 
    return Dp[n][m];
}

int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << Solve(str1, str2) << endl;
    return 0;
}


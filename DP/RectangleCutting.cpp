#include <bits/stdc++.h>
using namespace std;

int Solve(int n, int m){
    if(n==1) return m-1;
    if(m==1) return n-1;
    if(n==m) return 0;
    vector<vector<int>> Dp(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++) Dp[i][1] = i-1, Dp[i][0] = 0;
    for(int j=1;j<=m;j++) Dp[1][j] = j-1, Dp[0][j] = 0;
    Dp[0][0] = 0;

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            int Ans = INT_MAX;
            for(int x=1; x<=min(i,j); x++){
                int val = 0;
                if(i-x) val += 1+Dp[i-x][x];
                if(j-x) val += 1+Dp[i][j-x];

                Ans = min(Ans, val);

                val = 0;
                if(i-x) val += 1+Dp[i-x][j];
                if(j-x) val += 1+Dp[x][j-x];

                Ans = min(Ans, val);
            }
            Dp[i][j] = Ans;
        }
    }
    return Dp[n][m];
}   

int main(){
    int n, m;
    cin >> n >> m;
    cout << Solve(n, m) << endl;
    return 0;
}


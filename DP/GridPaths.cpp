#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int Solve(int n, vector<string>& grid){
    vector<vector<int>> Dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*'){
                Dp[i][j] = -1;
                continue;
            }

            if(i==0 && j==0) Dp[i][j] = 1;
            else if(i==0){
                Dp[i][j] = Dp[i][j-1];
            }else if(j==0){
                Dp[i][j] = Dp[i-1][j];
            }else{
                Dp[i][j] = ((Dp[i-1][j]==-1 ? 0 : (ll)Dp[i-1][j]) + (Dp[i][j-1]==-1 ? 0 : (ll)Dp[i][j-1]))%mod;
            }
        }
    }
    return Dp[n-1][n-1] == -1 ? 0 : Dp[n-1][n-1];
}

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    cout << Solve(n, grid) << endl;
    return 0;
}


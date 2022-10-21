#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

int Solve(int n){
    int sum = 0;
    for(int i=1;i<=n;i++) sum += i;
    if(sum%2) return 0;

    sum /= 2;
    vector<vector<int>> Dp(n+1,vector<int>(sum+1,0));
    for(int i=0;i<=n;i++) Dp[i][0] = 1;
  
    
    for(int j=1;j<=sum;j++){
        for(int i=1;i<=n;i++){
            if(j >= i){
                Dp[i][j] = ((ll)Dp[i-1][j] + (ll)Dp[i-1][j-i])%mod;
            }else{
                Dp[i][j] = Dp[i-1][j];
            }
        }
    }
    // cout << Dp[n-2][1] << endl;
    return Dp[n-1][sum];
}
int main(){
    int n;
    cin >> n;
    cout << Solve(n) << endl;
    return 0;
}


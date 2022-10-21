#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

int Cal(int n, int m, vector<vector<int>>& Dp){
    for(int j=1;j<=m;j++) Dp[0][j] = 1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            Dp[i][j] = ((ll)Dp[i-1][j-1] + (ll)Dp[i-1][j] + (ll)Dp[i-1][j+1])%mod;
        }
    }
    ll Ans = 0;
    for(int j=1;j<=m;j++) Ans = (Ans+(ll)Dp[n-1][j])%mod;
    return Ans;
}

int Solve(int n, int m, vector<int>& vec){
    vector<vector<int>> Dp(n,vector<int>(m+2,0));

    int start = 0;
    while(start<n && vec[start]==0) start++;
    if(start==n) return Cal(n,m,Dp);

    ll Ans = 1;
    for(int i=start;i<n;i++){
        if(vec[i]!=0){
            Dp[i][vec[i]] = 1;
            if(i!=start && vec[i-1]==0){
                int j = vec[i];
                ll val = ((ll)Dp[i-1][j-1] + (ll)Dp[i-1][j] + (ll)Dp[i-1][j+1])%mod;
                Ans = (Ans*val)%mod; 
            }else if(i!=start && vec[i-1]!=0){
                if(abs(vec[i]-vec[i-1]) > 1) return 0;
            }
        }else{
            for(int j=1;j<=m;j++){
                Dp[i][j] = ((ll)Dp[i-1][j-1] + (ll)Dp[i-1][j] + (ll)Dp[i-1][j+1])%mod;
            }
        }
    }

    ll val = 0;
    if(start!=0){
        Dp[start][vec[start]] = 1;
        for(int i=start-1;i>=0;i--){
            for(int j=1;j<=m;j++){
                Dp[i][j] = ((ll)Dp[i+1][j-1] + (ll)Dp[i+1][j] + (ll)Dp[i+1][j+1])%mod;
            }
        }
    }

    if(vec[0]==0){
        for(int j=1;j<=m;j++){
            val = (val+Dp[0][j])%mod;
        }
    }
    if(val) Ans = (Ans*val)%mod;
    val = 0;
    if(vec[n-1]==0){
        for(int j=1;j<=m;j++){
            val = (val+Dp[n-1][j])%mod;
        }
    }
    if(val) Ans = (Ans*val)%mod;
    return Ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    
    cout << Solve(n, m, vec) << endl;
    return 0;
}


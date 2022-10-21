

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int Solve(int n, vector<ll>& vec){
    vector<vector<pair<ll,ll>>> Dp(n,vector<pair<ll,ll>>(n,{0,0}));
    for(int i=0;i<n;i++) Dp[i][i] = {vec[i],0};
 
    for(int len=2;len<=n;len++){
        for(int i=0,j=len-1; j<n; i++,j++){
            if(vec[i] + Dp[i+1][j].second >= vec[j] + Dp[i][j-1].second){
                Dp[i][j] = {vec[i] + Dp[i+1][j].second, Dp[i+1][j].first};
            }else{
                Dp[i][j] = {vec[j] + Dp[i][j-1].second, Dp[i][j-1].first};
            }
        }
    }
    return Dp[0][n-1].first;
}
int main(){
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    cout << Solve(n, vec) << endl;
    return 0;
}


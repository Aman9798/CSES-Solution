#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

int Solve(int n){
    vector<int> Dp(n+1);
    Dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=max(0,i-6); j<=i-1; j++){

            Dp[i] = ((ll)Dp[i] + (ll)Dp[j])%mod;
        }
    }
    return Dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << Solve(n) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

int last;
vector<vector<int>> Dp(1000001,vector<int>(7));
int Solve(int n){
    if(last==-1){
        for(int j=1;j<=6;j++) Dp[1][j] = 1;
        for(int i=2;i<=n;i++){
            Dp[i][1] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
            Dp[i][2] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
            Dp[i][3] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
            Dp[i][4] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
            Dp[i][5] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][5]+(ll)Dp[i-1][6])%mod;
            Dp[i][6] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][5]+(ll)Dp[i-1][6])%mod;
        }
        return ((ll)Dp[n][1]+(ll)Dp[n][5])%mod;
    }
    
    if(n <= last){
        return ((ll)Dp[n][1]+(ll)Dp[n][5])%mod;
    }

    for(int i=last+1;i<=n;i++){
        Dp[i][1] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
        Dp[i][2] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
        Dp[i][3] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
        Dp[i][4] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][2]+(ll)Dp[i-1][3]+(ll)Dp[i-1][4]+(ll)Dp[i-1][5])%mod;
        Dp[i][5] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][5]+(ll)Dp[i-1][6])%mod;
        Dp[i][6] = ((ll)Dp[i-1][1]+(ll)Dp[i-1][5]+(ll)Dp[i-1][6])%mod;
    }
    return ((ll)Dp[n][1]+(ll)Dp[n][5])%mod;

}

int main(){
    int t;
    cin >> t;
    last = -1;
    while(t--){
        int n;
        cin >> n;
        cout << Solve(n) << endl;
        last = n;
    }
    return 0;
}


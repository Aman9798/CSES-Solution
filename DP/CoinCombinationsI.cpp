#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

int Solve(int n, int x, vector<int>& cns){
    sort(cns.begin(),cns.end());

    vector<int> Dp(x+1,0);
    Dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(cns[j] > i) break;

            Dp[i] = ((ll)Dp[i]+(ll)Dp[i-cns[j]])%mod;
        }
    }
    return Dp[x];
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> cns(n);
    for(int i=0;i<n;i++) cin >> cns[i];
    cout << Solve(n, x, cns) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

int Solve(int n, int x, vector<int>& cns){
    sort(cns.begin(),cns.end());

    vector<int> Dp(x+1,0);
    Dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=cns[i]; j<=x; j++){
            Dp[j] = ((ll)Dp[j]+(ll)Dp[j-cns[i]])%mod;
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


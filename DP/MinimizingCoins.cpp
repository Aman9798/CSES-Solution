#include <bits/stdc++.h>
using namespace std;

int Solve(int n, int x, vector<int>& cns){
    sort(cns.begin(),cns.end());

    vector<int> Dp(x+1,INT_MAX);
    Dp[0] = 0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(cns[j] > i) break;

            if(Dp[i-cns[j]] != INT_MAX) Dp[i] = min(Dp[i],1+Dp[i-cns[j]]);
        }
    }
    return Dp[x]==INT_MAX ? -1 : Dp[x];
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> cns(n);
    for(int i=0;i<n;i++) cin >> cns[i];
    cout << Solve(n, x, cns) << endl;
    return 0;
}


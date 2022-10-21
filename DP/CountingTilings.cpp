#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

void Generate(int OrgMask, int i, int mask, int n, vector<int>& nxt_masks){
    if(i == n + 1){
        nxt_masks.push_back(mask);
        return;
    }
      
    if((OrgMask & (1 << i)) != 0) Generate(OrgMask, i + 1, mask, n, nxt_masks);
      
    if(i != n && ((OrgMask & (1 << i)) == 0 && (OrgMask & (1 << (i+1))) == 0)){
        Generate(OrgMask, i + 2, mask, n, nxt_masks);      
    }
        
    if((OrgMask & (1 << i)) == 0){
        Generate(OrgMask, i + 1, mask + (1 << i), n, nxt_masks);    
    }
}

int Solve(int col, int mask, int n, int m, vector<vector<int>>& Dp){
    if(col == m+1) return (mask==0) ? 1 : 0;

    if(Dp[col][mask]!=-1) return Dp[col][mask];

    vector<int> nxt_masks;
    ll Ans = 0;
    Generate(mask, 1, 0, n, nxt_masks);

    for(int next : nxt_masks){
        Ans = (Ans + (ll)Solve(col+1, next, n, m, Dp))%mod;
    }
    return Dp[col][mask] = Ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Dp(m+1,vector<int>((1<<(n+1)),-1));
    cout << Solve(1, 0, n, m, Dp) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
 
#define ll long long

 
int Solve(ll n, ll x, vector<ll>& vec){
    ll size = 1 << n;
    vector<pair<int,ll>> Dp(size);
    Dp[0] = {1,0};

    for(int mask=1;mask<size;mask++){
        pair<ll,ll> Ans = {LLONG_MAX,LLONG_MAX};
        for(int i=0;i<n;i++){
            if((mask & (1 << i)) == 0) continue;

            pair<ll,ll> res = Dp[mask ^ (1<<i)];
            if(res.second + vec[i] <= x){
                res.second += vec[i];
            }else{
                res.second = vec[i];
                res.first++;
            }
            Ans = min(Ans,res);
        }
        Dp[mask] = Ans;
    }
    return Dp[size-1].first;
}
 
int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    
    cout << Solve(n, x, vec) << endl;
    return 0;
}
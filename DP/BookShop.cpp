#include <bits/stdc++.h>
using namespace std;

int Solve(int n, int x, vector<int>& price, vector<int>& page){

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= price[i-1]){
                dp[i][j] = max (dp[i][j],dp[i-1][j-price[i-1]] + page[i-1]);
            }
        }
    }
    return dp[n][x];

}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    for(int i=0;i<n;i++) cin >> price[i];
    vector<int> page(n);
    for(int i=0;i<n;i++) cin >> page[i];

    cout << Solve(n, x, price, page) << endl;
    return 0;
}


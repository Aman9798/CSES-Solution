#include <bits/stdc++.h>
using namespace std;

void Solve(int n, vector<int>& vec){
    int sum = 0;
    for(int i=0;i<n;i++) sum += vec[i];
    vector<vector<bool>> Dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<=n;i++) Dp[i][0] = true;
    for(int j=1;j<=sum;j++) Dp[0][j] = false;
    
    for(int j=1;j<=sum;j++){
        for(int i=1;i<=n;i++){
            if(j >= vec[i-1]){
                Dp[i][j] = Dp[i-1][j] | Dp[i-1][j-vec[i-1]];
            }else{
                Dp[i][j] = Dp[i-1][j];
            }
        }
    }

    vector<int> ans;
    for(int j=1;j<=sum;j++) if(Dp[n][j]) ans.push_back(j);

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    return;
}   

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    Solve(n, vec);
    return 0;
}


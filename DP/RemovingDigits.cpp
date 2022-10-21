#include <bits/stdc++.h>
using namespace std;

int Solve(int n){
    vector<int> Dp(n+1,INT_MAX);
    Dp[0] = 0;
    for(int i=1;i<=n;i++){
        int temp = i;
        while(temp){
            int r = temp%10;
            temp /= 10;
            
            if(Dp[i-r]!=INT_MAX) Dp[i] = min(Dp[i],1+Dp[i-r]);

        }
    }
    return Dp[n];
}

int main(){
    int n, x;
    cin >> n;
    cout << Solve(n) << endl;
    return 0;
}


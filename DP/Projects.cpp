#include <bits/stdc++.h>
using namespace std;

#define ll long long

int Binary(vector<int>& arr, int val, int l){
    int r = arr.size()-1;
    int ans = r+1;
    while(l <= r){
        int m = l+(r-l)/2;
        if(arr[m] > val){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    return ans;
}

ll Solve(int n, vector<int>& start, vector<int>& end, vector<int>& money){

    vector<pair<int,int>> vec(n);
    for(int i=0;i<n;i++) vec[i] = {start[i],i};
    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++) start[i] = vec[i].first;
    
    vector<int> temp = end;
    for(int i=0;i<n;i++) end[i] = temp[vec[i].second];

    temp = money;
    for(int i=0;i<n;i++) money[i] = temp[vec[i].second];

    vector<ll> Dp(n+1);
    Dp[n] = 0;
    Dp[n-1] = money[n-1];

    for(int i=n-2;i>=0;i--){
        int ind = Binary(start, end[i], i+1);
        ll cost1 = money[i] + Dp[ind];
        ll cost2 = Dp[i+1];

        Dp[i] = max(cost1,cost2);
    }
    return Dp[0];
}   

int main(){
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    vector<int> money(n);
    for(int i=0;i<n;i++) cin >> start[i] >> end[i] >> money[i];
    cout << Solve(n, start, end, money) << endl;
    return 0;
}


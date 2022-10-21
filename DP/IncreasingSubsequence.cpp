#include <bits/stdc++.h>
using namespace std;

int Find(vector<int>& st, int x){
    int l = 0;
    int r = st.size()-1;
    if(x > st[r]) return r+1;
    if(x <= st[l]) return 0;
    if(x >= st[r]) return r;

    int ans = r+1;
    while(l <= r){
        int m = l+(r-l)/2;
        if(st[m] > x){
            ans = m;
            r = m-1;
        }else if(st[m]==x){
            return m;
        }else{
            l = m+1;
        }
    }
    return ans;
}


int Solve(int n, vector<int>& vec){
    vector<int> st;
    st.push_back(vec[0]);
    for(int i=1;i<n;i++){
        int ind = Find(st, vec[i]);
        if(ind==(int)st.size()){
            st.push_back(vec[i]);
        }else{
            st[ind] = vec[i];
        }
    }
    return st.size();
}   

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];
    cout << Solve(n, vec) << endl;
    return 0;
}


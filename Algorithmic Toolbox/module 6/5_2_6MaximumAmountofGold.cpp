#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int maximunValue(int W, int n, vector<int> &w){
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=W; ++j){
            dp[i][j] = dp[i-1][j];
            if(w[i-1] <= j) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+w[i-1]);
        }
    }
    return dp[n][W];
}


int main(){
    int W,n;
    cin >> W >> n;

    vector<int> w(n);
    for(int i=0; i<n; ++i) cin >> w[i];
    
    cout << maximunValue(W, n, w);
    
    return 0;
}
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int number(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(int m=1; m <= n; ++m){
        if(m>=1) dp[m] = min(dp[m], dp[m-1]+1);
        if(m>=3) dp[m] = min(dp[m], dp[m-3]+1);
        if(m>=4) dp[m] = min(dp[m], dp[m-4]+1);
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    int a = number(n);
    cout << a;
    return 0;
}
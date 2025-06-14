#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistance(string a, string b){
    int la=a.length();
    int lb=b.length();
    // int ans=0;
    vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));

    for(int i=0;i<=la;++i) dp[i][0]=i;
    for(int i=0;i<=lb;++i) dp[0][i]=i;

    for(int i=1;i<=la;++i){
        for(int j=1;j<=lb;++j){

            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else{ 
                int insertion = dp[i][j-1] + 1;
                int deletion = dp[i-1][j] + 1;
                int substitution = dp[i-1][j-1] + 1;
                dp[i][j] = min(insertion, min(deletion, substitution));

            }
        }
    }
    return dp[la][lb];
}

int main(){
    string a, b;
    getline(cin,a);
    getline(cin,b);
    cout << editDistance(a,b);
    return 0;
}
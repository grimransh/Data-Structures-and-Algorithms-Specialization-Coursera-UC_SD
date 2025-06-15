#include<iostream>
#include<vector>
using namespace std;

int LCS3(int n, int m, int l, vector<int> a, vector<int> b, vector<int> c){
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(l + 1, 0)));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            for(int k=1; k<=l; ++k){
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k-1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i][j - 1][k], max(dp[i - 1][j][k], dp[i][j][k - 1]));
            }
        }
    }
    return dp[n][m][l];
}

int main(){
    int n, m, l;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    cin >> l;
    vector<int> c(l);
    for (int i = 0; i < l; ++i) cin >> c[i];

    cout << LCS3(n, m, l, a, b, c);

    return 0;
}
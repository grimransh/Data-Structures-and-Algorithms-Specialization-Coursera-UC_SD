#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

long long eval(long long a, long long b, char op) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else return a * b;
}

vector<long long> MinAndMax(int i, int j, vector<vector<long long>> & minimum, vector<vector<long long>> & maximum, string & s){
    vector<long long> ans(2);
    ans[0] = LLONG_MAX;
    ans[1] = LLONG_MIN;

    for(int k=i; k<j; ++k){
        long long a = eval(maximum[i][k], maximum[k+1][j], s[2*k + 1]);
        long long b = eval(maximum[i][k], minimum[k+1][j], s[2*k + 1]);
        long long c = eval(minimum[i][k], minimum[k+1][j], s[2*k + 1]);
        long long d = eval(minimum[i][k], maximum[k+1][j], s[2*k + 1]);
        ans[0] = min(ans[0], min(a, min(b, min(c, d))));
        ans[1] = max(ans[1], max(a, max(b, max(c, d))));             
    }
    return ans;
}
long long MaxValue(string & s){
    int n=(s.length() + 1) / 2;
    vector<vector<long long>> maximum(n, vector<long long>(n));
    vector<vector<long long>> minimum(n, vector<long long>(n));
    
    for(int i=0; i<n; ++i){
        maximum[i][i]=s[2*i]-'0';
        minimum[i][i]=s[2*i]-'0';
    }
    for(int len=1; len<n; ++len){
        for(int i=0; i<n-len; ++i){
            int j=i+len;
            vector<long long> ans = MinAndMax(i,j,minimum,maximum,s);
            minimum[i][j]=ans[0];
            maximum[i][j]=ans[1];
        }
    }
    return maximum[0][n-1];
}


int main(){
    string s;
    getline(cin, s);
    cout << MaxValue(s);

    return 0;
}